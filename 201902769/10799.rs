fn main() {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    
    let mut answer = 0;
    let mut stack = Vec::new();
    let mut prev_char = ' ';

    for c in s.chars() {
        match c {
            '(' => {
                stack.push(c);
            },
            ')' => {
                stack.pop();
                if prev_char == '(' {
                    // 레이저인 경우
                    answer += stack.len();
                } else {
                    // 쇠막대기의 끝인 경우
                    answer += 1;
                }
            },
            '\n' => {},
            _ => panic!()
        }
        prev_char = c;
    }

    print!("{}", answer);
}