use std::{collections::VecDeque, io::{self, BufRead, Read}};

fn find_index(x: usize, y: usize) -> (usize, usize) {
    (x/3*3, y/3*3)
}

fn valid_numbers(v: &Vec<Vec<u32>>, x: usize, y: usize, target: u32) -> bool {
    for i in 0..9 {
        
        if v[y][i] == target || v[i][x] == target {
            return false;
        }
    }

    let (x, y) = find_index(x, y);
    for y in y..y+3 {
        for x in x..x+3 {
            if v[y][x] == target {
                return false;
            }
        }
    }

    true
}

fn recursion(v: &mut Vec<Vec<u32>>) -> bool {
    for y in 0..9 {
        for x in 0..9 {
            if v[y][x] == 0 {
                for target in 1..10 {
                    if valid_numbers(v, x, y, target) {
                        v[y][x] = target;
                        if recursion(v) {
                            break;
                        }
                        else {
                            v[y][x] = 0;
                        }
                    }
                }
                if  v[y][x] == 0 {
                        return false;
                    }
            }
        }
    }
    true
}

fn main() {
    let mut stdin = std::io::stdin().lock();

    let mut buf = String::new();
    let mut lines: Vec<Vec<u32>> = Vec::new();

    for _ in 0..9 {
        buf.clear();
        stdin.read_line(&mut buf).unwrap();
        
        let mut line: Vec<u32> = buf.trim().chars().filter_map(|x| x.to_digit(10)).collect();
        lines.push(line);
    }
    
    recursion(&mut lines);
    for i in 0..9 {
        for j in 0..9 {
            print!("{}", lines[i][j]);
        }
        println!();
    }
}