import sys
# 직사각형에서 탈출
x,y,w,h = list(map(int, sys.stdin.readline().split()))
result = min(abs(x-w), abs(y-h), abs(0-x), abs(y-0))
print(result)