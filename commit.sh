# 
#!/bin/bash

# 문제 번호 입력 받기
problem_number=$1

# 문제 제목 가져오기
page=$(curl -s "https://www.acmicpc.net/problem/$problem_number" -A "Mozilla/4.0 (compatible; MSIE 6.0; Windows NT 5.1; SV1; .NET CLR 1.0.3705; .NET CLR 1.1.4322)")
title=$(grep "<span id=\"problem_title\">" <<< "$page")
temp=$(sed 's/<span id="problem_title">//g' <<< "$title")
name=$(sed 's/<\/span>//g' <<< "$temp")

# 커밋 메시지 생성
commit_message="${problem_number}번${name}"

# 파일 추가 및 커밋
git add "201902769/${problem_number}.rs"
git commit -m "$commit_message"
git push origin 201902769

echo "문제 번호 ${problem_number}, 제목 ${name}로 커밋 완료"