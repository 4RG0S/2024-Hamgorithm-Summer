use std::io::{self, BufRead};

fn balance(s: &str) -> bool {
    let mut stack = Vec::new();
    for ch in s.chars() {
        if ch == '.' {
            break;
        }
        
        match ch {
            '(' | '[' => stack.push(ch),
            ')' => {
                if stack.pop() != Some('(') {
                    return false;
                }
            }
            ']' => {
                if stack.pop() != Some('[') {
                    return false;
                }
            },
            _ => {}
        }
    }
    
    stack.is_empty()
}

fn main() {
    let stdin = io::stdin();
    let lines = stdin.lock().lines();
    
    for line in lines {
        let input = line.unwrap();
        if input == "." {
            break;
        }
        
        if balance(&input) {
            println!("yes");
        } else {
            println!("no");
        }
    }
}