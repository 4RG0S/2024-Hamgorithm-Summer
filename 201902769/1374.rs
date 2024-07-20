use std::{cmp::max, collections::BinaryHeap, io::BufRead};

fn main() {
    let stdin = std::io::stdin();
    let mut stdin = stdin.lock();

    let mut buf = String::new();
   
    stdin.read_line(&mut buf).unwrap();

    let n = buf.trim().parse().unwrap();
    let mut lecutre_schedule: Vec<(i32, i32)> = Vec::new();

    for _ in 0..n {
        buf.clear();
        stdin.read_line(&mut buf).unwrap();

        let mut iter = buf.trim().split_whitespace();
        let (_, b, c) = (iter.next().unwrap(), iter.next().unwrap().parse().unwrap(), iter.next().unwrap().parse().unwrap());
        
        lecutre_schedule.push((b, c));
    }
    lecutre_schedule.sort();

    let mut answer = 0;

    let mut hq  = BinaryHeap::new();
    for (start, end) in lecutre_schedule {
        while hq.len() > 0 {
            if -hq.peek().unwrap() > start {
                break;
            }
            hq.pop();
        }

        hq.push(-end);
        answer = max(answer, hq.len());
    }

    print!("{}", answer);
}