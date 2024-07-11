use std::io::{self, BufRead};

const MX: usize = 1000005;
static mut DAT: [char; MX] = ['\0'; MX];
static mut PRE: [i32; MX] = [-1; MX];
static mut NXT: [i32; MX] = [-1; MX];
static mut UNUSED: usize = 1;

fn insert(addr: usize, c: char) {
    unsafe {
        DAT[UNUSED] = c;
        PRE[UNUSED] = addr as i32;
        NXT[UNUSED] = NXT[addr];
        
        if NXT[addr] != -1 {
            PRE[NXT[addr] as usize] = UNUSED as i32;
        }
        NXT[addr] = UNUSED as i32;
        UNUSED += 1;
    }
}

fn erase(addr: usize) {
    unsafe {
        NXT[PRE[addr] as usize] = NXT[addr];
        if NXT[addr] != -1 {
            PRE[NXT[addr] as usize] = PRE[addr];
        }
    }
}

fn traverse() {
    unsafe {
        let mut cur = NXT[0];
        while cur != -1 {
            print!("{}", DAT[cur as usize]);
            cur = NXT[cur as usize];
        }
        println!();
    }
}

fn main() {
    let stdin = io::stdin();
    let mut handle = stdin.lock();

    let mut input = String::new();
    handle.read_line(&mut input).unwrap();
    let initial_string = input.trim_end();

    let mut cursor = 0;
    for c in initial_string.chars() {
        insert(cursor, c);
        cursor = unsafe { NXT[cursor] as usize };
    }

    input.clear();
    handle.read_line(&mut input).unwrap();
    let m: usize = input.trim().parse().unwrap();

    for _ in 0..m {
        input.clear();
        handle.read_line(&mut input).unwrap();
        let command = input.trim();

        match &command[..1] {
            "L" => {
                if cursor != 0 {
                    cursor = unsafe { PRE[cursor] as usize };
                }
            }
            "D" => {
                if unsafe { NXT[cursor] } != -1 {
                    cursor = unsafe { NXT[cursor] as usize };
                }
            }
            "B" => {
                if cursor != 0 {
                    let to_erase = cursor;
                    cursor = unsafe { PRE[cursor] as usize };
                    erase(to_erase);
                }
            }
            "P" => {
                let c = command.chars().nth(2).unwrap();
                insert(cursor, c);
                cursor = unsafe { NXT[cursor] as usize };
            }
            _ => {}
        }
    }

    traverse();
}