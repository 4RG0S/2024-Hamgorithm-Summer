use std::io::BufRead;

fn calculate_distance(x1: i32, y1: i32, x2: i32, y2: i32) -> i32 {
    (x1-x2) * (x1-x2) + (y1-y2) * (y1-y2)
}

fn inner_circle(x1: i32, y1: i32, x2: i32, y2: i32, r: i32) -> bool {
    calculate_distance(x1, y1, x2, y2) < r * r // 행성계의 경계가 맞닿거나 서로 교차하는 경우는 없다
}

fn main() {
    let mut stdin = std::io::stdin().lock();
    let mut buf = String::new();

    stdin.read_line(&mut buf).unwrap();
    let t: usize = buf.trim().parse().unwrap();

    for _ in 0..t {
        buf.clear();
        stdin.read_line(&mut buf).unwrap();

        let mut iter = buf.split_whitespace().map(|x| x.parse::<i32>().unwrap());
        let (x1, y1, x2, y2) = (iter.next().unwrap(), iter.next().unwrap(), iter.next().unwrap(), iter.next().unwrap());

        buf.clear();
        stdin.read_line(&mut buf).unwrap();
        let n: usize = buf.trim().parse().unwrap();
        let mut count = 0;

        for _ in 0..n {
            buf.clear();
            stdin.read_line(&mut buf).unwrap();

            let mut iter = buf.split_whitespace().map(|x| x.parse::<i32>().unwrap());
            let (x, y, r) = (iter.next().unwrap(), iter.next().unwrap(), iter.next().unwrap());

            match (inner_circle(x1, y1, x, y, r), inner_circle(x2, y2, x, y, r)) {
                (true, true) => {}
                (true, false) => count += 1,
                (false, true) => count += 1,
                (false, false) => {},
            }
        }

        println!("{}", count);
    }
}