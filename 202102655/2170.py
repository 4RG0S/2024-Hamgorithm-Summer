# 2170번 - 선 긋기

import sys
input = sys.stdin.readline

n = int(input())
lines = []
ans = 0

for _ in range(n):
    lines.append(list(map(int, input().split())))

lines.sort()

start, end = lines[0]
for i in range(1, n):
    if lines[i][0] <= end:
        end = max(end, lines[i][1])
    else:
        ans += end - start
        start, end = lines[i]
ans += end - start
print(ans)