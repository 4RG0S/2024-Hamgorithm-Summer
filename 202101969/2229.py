# 조 짜기

import sys
input = sys.stdin.readline

N = int(input().strip())
student_scores = list(map(int, input().split()))

dp = [0] * (N + 1)

for i in range(1, N + 1):
    for j in range(i - 1, -1, -1):
        team_score = max(student_scores[j:i]) - min(student_scores[j:i])
        dp[i] = max(dp[i], dp[j] + team_score)

print(dp[-1])
