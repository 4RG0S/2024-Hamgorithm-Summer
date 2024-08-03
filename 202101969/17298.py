import sys

n = int(sys.stdin.readline())
result = [-1]*n
ar = list(map(int, sys.stdin.readline().split()))
stack = [0]
for i in range(1, len(ar)):
    while stack and ar[stack[-1]] < ar[i]:
        result[stack.pop()] = ar[i]
    stack.append(i)
print(*result)