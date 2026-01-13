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

                if (1..)
                    .take_while(|&j| j * j <= n)
                    .map(|j| {
                        if n % j != 0 {
                            return false;
                        }

                        let f = |j| {
                            if j == n {
                                return false;
                            }

                            for k in 1..n / j {
                                if s[0..j] != s[k * j..(k + 1) * j] {
                                    return false;
                                }
                            }
                            true
                        };

                        f(j) || f(n / j)
                    })
                    .any(|x| x)
                {
                    eprintln!("{i}");
                    res += i;
                }
            }

            res
        })
        .sum::<i64>();

    println!("{res}");
}

