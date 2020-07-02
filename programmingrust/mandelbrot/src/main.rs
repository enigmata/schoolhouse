
use std::str::FromStr;
use std::fs::File;
use std::io::Write;
use std::io::{Error, ErrorKind};

extern crate num;
use num::Complex;

extern crate image;
use image::ColorType;
use image::png::PNGEncoder;

extern crate crossbeam;

fn parse_cmdline_arg<T: FromStr>(args: &str, arg_separator: char) -> Option<(T, T)> {
    match args.find(arg_separator) {
        None => None,
        Some(index) => {
            match (T::from_str(&args[..index]), T::from_str(&args[index + 1..])) {
                (Ok(lhs), Ok(rhs)) => Some((lhs, rhs)),
                _ => None
            }
        }
    }
}

#[test]
fn test_parse_cmdline_arg() {
    assert_eq!(parse_cmdline_arg::<i32>("",        ','), None);
    assert_eq!(parse_cmdline_arg::<i32>("10,",     ','), None);
    assert_eq!(parse_cmdline_arg::<i32>(",10",     ','), None);
    assert_eq!(parse_cmdline_arg::<i32>("10,20",   ','), Some((10,20)));
    assert_eq!(parse_cmdline_arg::<i32>("10,20xy", ','), None);
    assert_eq!(parse_cmdline_arg::<f64>("0.5x",    'x'), None);
    assert_eq!(parse_cmdline_arg::<f64>("0.5x1.5", 'x'), Some((0.5, 1.5)));
}

fn parse_complex_cmdline_arg(args: &str) -> Option<Complex<f64>> {
    match parse_cmdline_arg(args, ',') {
        Some((re, im)) => Some(Complex{ re, im }),
        None => None
    }
}

#[test]
fn test_parse_complex_cmdline_arg() {
    assert_eq!(parse_complex_cmdline_arg("1.25,-0.0625"), Some(Complex{re: 1.25, im: -0.0625}));
    assert_eq!(parse_complex_cmdline_arg("2.3, "), None);
    assert_eq!(parse_complex_cmdline_arg(", 0.45"), None);
    assert_eq!(parse_complex_cmdline_arg("1.25 x -0.45"), None);
    assert_eq!(parse_complex_cmdline_arg(","), None);
}

fn map_img_pixel_to_complex_plane(img_size: (usize, usize),
                                  img_pixel: (usize, usize),
                                  img_coords_top_left: Complex<f64>,
                                  img_coords_bot_right: Complex<f64>) -> Complex<f64>
{
    let (img_width, img_height) = (img_coords_bot_right.re - img_coords_top_left.re,
                                   img_coords_top_left.im - img_coords_bot_right.im);
    Complex{
        re: img_coords_top_left.re + img_pixel.0 as f64 * img_width / img_size.0 as f64,
        im: img_coords_top_left.im - img_pixel.1 as f64 * img_height / img_size.1 as f64
    }
}

#[test]
fn test_map_img_pixel_to_complex_plane() {
    assert_eq!(map_img_pixel_to_complex_plane((100, 100), (25, 75),
                                              Complex { re: -1.0, im: 1.0 },
                                              Complex { re: 1.0, im: -1.0 }),
                                              Complex { re: -0.5, im: -0.5 });
}

fn render_img(img: &mut [u8],
              size: (usize, usize),
              coords_top_left: Complex<f64>,
              coords_bot_right: Complex<f64>)
{
    assert!(img.len() == size.0 * size.1);
    for row in 0..size.1 {
        for col in 0..size.0 {
            let point= map_img_pixel_to_complex_plane(size,
                                                       (col, row),
                                                       coords_top_left,
                                                       coords_bot_right);
            img[row * size.0 + col] =
                match escape_time(point, 255) {
                    None => 0,
                    Some(count) => 255 - count as u8
                };
        }
    }
}

fn concurrent_render_img(img: &mut [u8],
                         size: (usize, usize),
                         coords_top_left: Complex<f64>,
                         coords_bot_right: Complex<f64>)
{
    let threads = 8;
    let rows_per_band = size.1 / threads + 1;
    {
        let bands: Vec<&mut [u8]> =
            img.chunks_mut(rows_per_band * size.0).collect();
        crossbeam::scope(|spawner| {
            for (i, band) in bands.into_iter().enumerate() {
                let top = rows_per_band * i;
                let height = band.len() / size.0;
                let band_bounds = (size.0, height);
                let band_top_left=
                    map_img_pixel_to_complex_plane(size, (0, top), coords_top_left, coords_bot_right);
                let band_bot_right =
                    map_img_pixel_to_complex_plane(size, (size.0, top + height), coords_top_left, coords_bot_right);
                spawner.spawn(move |_| {
                    render_img(band, band_bounds, band_top_left, band_bot_right);
                });
            }
        });
    }
}

fn escape_time(mandelbrot_candidate: Complex<f64>, iteration_limit: u32) -> Option<u32> {
    let mut z = Complex {re: 0.0, im: 0.0 };
    for i in 0..iteration_limit {
        z = z * z + mandelbrot_candidate;
        if z.norm_sqr() > 4.0 {
            return Some(i);
        }
    }
    None
}

fn write_img(filename: &str, img: &[u8], img_size: (usize, usize))
    -> Result<(), std::io::Error>
{
    let file = File::create(filename)?;
    let encoder = PNGEncoder::new(file);
    match encoder.encode(&img, img_size.0 as u32, img_size.1 as u32, ColorType::L8) {
        Err(_e) => Err(Error::new(ErrorKind::Other, "encode failed")),
        Ok(_o) => Ok(())
    }
}



fn main() {
    let args: Vec<String> = std::env::args().collect();

    if args.len() != 5 {
        writeln!(std::io::stderr(),
                 "Usage: {} <png filename> <image size> <upper-left coords> <lower-right coords>",
                 args[0])
            .unwrap();
        writeln!(std::io::stderr(),
                 "Example: {} mandel.png 1000x750 -1.20,0.35 -1,0.20", args[0])
            .unwrap();
        std::process::exit(1);
    }
    let image_size = parse_cmdline_arg(&args[2], 'x')
        .expect("error parsing image dimensions");
    let upper_left_coord = parse_complex_cmdline_arg(&args[3])
        .expect("error parsing upper-left coordinate");
    let lower_right_coord = parse_complex_cmdline_arg(&args[4])
        .expect("error parsing lower-right coordinate");
    let mut image = vec![0; image_size.0 * image_size.1];
    concurrent_render_img(&mut image, image_size, upper_left_coord, lower_right_coord);
    write_img(&args[1], &image, image_size)
        .expect("error writing image file");
}
