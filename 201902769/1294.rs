use std::{cmp::{Ordering, Reverse}, collections::BinaryHeap, io::BufRead};

#[derive(Eq, PartialEq)]
struct CustomString(String);

impl Ord for CustomString {
    fn cmp(&self, other: &Self) -> Ordering {
        let len_cmp = self.0.len().cmp(&other.0.len());
        match len_cmp {
            Ordering::Equal => self.0.cmp(&other.0), // 길이가 같다면 사전식 비교
            _ => {
                // 길이가 다르면 짧은 길이의 문자열과 1대1로 비교
                let min_len = self.0.len().min(other.0.len());
                let short_str = &self.0[..min_len];
                let long_str = &other.0[..min_len];
                match short_str.cmp(long_str) {
                    Ordering::Equal => len_cmp.reverse(), // 짧은 길이와 비교 후 일치하면 더 긴 쪽이 작음
                    other => other, // 일치하지 않으면 사전식 비교 결과 반환
                }
            }
        }
    }
}

impl PartialOrd for CustomString {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}

fn main() {
    let stdin = std::io::stdin();
    let mut stdin = stdin.lock();

    let mut buf = String::new();
   
    stdin.read_line(&mut buf).unwrap();

    let n = buf.trim().parse().unwrap();
    let mut hq  = BinaryHeap::new();

    for _ in 0..n {
        buf.clear();
        stdin.read_line(&mut buf).unwrap();

        let input: CustomString = CustomString(buf.trim().to_string());
        hq.push(Reverse(input));
    }

    while let Some(Reverse(str)) = hq.pop() {
        let mut iter = str.0.chars();
        let first = iter.next().unwrap();
        let other: CustomString = CustomString(iter.collect());

        print!("{}", first);

        if other.0.is_empty() {
            continue;
        }
        else {
            hq.push(Reverse(other));
        }
    }
    
}