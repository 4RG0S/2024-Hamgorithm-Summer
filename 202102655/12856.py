# 12865번 - 평범한 배낭

n, weight = map(int, input().split())
arr = [(0, 0)]

for _ in range(n):
    a, b = map(int, input().split())
    arr.append((a, b))

dp = [[0] * (weight + 1) for _ in range(n + 1)]  # dp생성

for i in range(1, n + 1):
    tmp_w, tmp_v = arr[i][0], arr[i][1]
    for j in range(1, weight + 1):
        if j < tmp_w:
            dp[i][j] = dp[i - 1][j]
        else:
            dp[i][j] = max(dp[i - 1][j - tmp_w] + tmp_v, dp[i - 1][j])

print(dp[-1][-1])
