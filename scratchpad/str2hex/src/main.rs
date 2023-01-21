use std::env;

fn main() {
    let mut src_string="HTTP";
    let args: Vec<String> = env::args().collect();
    if args.len() == 2 {
        src_string=&args[1];
    }

    let mut multiplier:u32=src_string.len() as u32;
    let mut ans:u32=0;
    for c in src_string.chars() {
        multiplier -= 1;
        ans+=(c as u32) * (100_u32.pow(multiplier));
    }
    println!("'{}' = 0x{:x}", src_string, ans);
}
