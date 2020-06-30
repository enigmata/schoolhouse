
use std::str::FromStr;

extern crate num;
use num::Complex;

#[allow(dead_code)]
fn parse_cmdline_args<T: FromStr>(args: &str, arg_separator: char) -> Option<(T, T)> {
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
fn test_parse_cmdline_args() {
    assert_eq!(parse_cmdline_args::<i32>("",        ','), None); 
    assert_eq!(parse_cmdline_args::<i32>("10,",     ','), None);
    assert_eq!(parse_cmdline_args::<i32>(",10",     ','), None);
    assert_eq!(parse_cmdline_args::<i32>("10,20",   ','), Some((10,20))); 
    assert_eq!(parse_cmdline_args::<i32>("10,20xy", ','), None); 
    assert_eq!(parse_cmdline_args::<f64>("0.5x",    'x'), None);
    assert_eq!(parse_cmdline_args::<f64>("0.5x1.5", 'x'), Some((0.5, 1.5)));
}

#[allow(dead_code)]
fn parse_complex_cmdline_args(args: &str) -> Option<Complex<f64>> {
    match parse_cmdline_args(args, ',') {
        Some((re, im)) => Some(Complex{ re, im }),
        None => None
    }
}

#[test]
fn test_parse_complex_cmdline_args() {
    assert_eq!(parse_complex_cmdline_args("1.25,-0.0625"), Some(Complex{re: 1.25, im: -0.0625}));
    assert_eq!(parse_complex_cmdline_args("2.3, "), None);
    assert_eq!(parse_complex_cmdline_args(", 0.45"), None);
    assert_eq!(parse_complex_cmdline_args("1.25 x -0.45"), None);
    assert_eq!(parse_complex_cmdline_args(","), None);
}

#[allow(dead_code)]
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

#[allow(dead_code)]
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

#[allow(dead_code)]
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

fn main() {
    println!("Hello, world!");
}
