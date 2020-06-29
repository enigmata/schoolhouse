
use std::str::FromStr;

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


extern crate num;
use num::Complex;

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
