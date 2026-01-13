use std::io::Read;

fn main() {
    let mut buf = String::new();
    std::io::stdin().read_to_string(&mut buf).unwrap();
    let buf = buf.trim();

    let res = buf
        .split(',')
        .map(|input| {
            let (x, y) = input.split_once('-').unwrap();
            let x: i64 = x.parse().unwrap();
            let y: i64 = y.parse().unwrap();

            let mut res = 0;

            for i in x..=y {
                let s = i.to_string();
                let n = s.len();
                if n % 2 == 0 && s[..n / 2] == s[n / 2..] {
                    eprintln!("{s}");
                    res += i;
                }
            }

            res
        })
        .sum::<i64>();

    println!("{res}");
}

