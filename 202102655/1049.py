# 1049번 - 기타줄

n, m = map(int, input().split())
package = []
single = []

for _ in range(m):
    a, b = map(int, input().split())
    package.append(a)
    single.append(b)

min_package = min(package)

ans = 0
while n > 0:
    if n >= 6:
        min_single = min(single)*6
        n -= 6
    else:
        min_single = min(single)*n
        n -= n
    if min_single < min_package:
        ans += min_single
    else:
        ans += min_package

print(ans)