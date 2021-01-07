use std::env;
use std::process; 

fn main() {
    let args: Vec<String> = env::args().collect();
    if args.len() < 2 {
        println!("Usage: digital_root <non-negative integer>");
        process::exit(1);
    } else {
        let n: i64 = args[1].parse().expect("not a positive integer");
        println!("sum={}", digital_root(n));
    }
}

fn digital_root(n: i64) -> i64 {
    match n as u32 {
        0 ..= 9 => n,
        _ => digital_root((n.to_string()
                            .chars()
                            .map(|c| c.to_digit(10).expect("must be digit"))
                            .sum::<u32>()).into())
    }
}
