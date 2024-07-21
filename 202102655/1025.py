# 1025번 - 제곱수 찾기
import sys
input = sys.stdin.readline

N, M = map(int, input().split())
board = [list(input().strip()) for _ in range(N)]
answer = -1

def sqr(S):
    S = int(S)
    return int(S**0.5) ** 2 == S


for i in range(N): #시작 x좌표
    for j in range(M): # 시작 y좌표
        for row_d in range(-N,N): # 행의 등차
            for col_d in range(-M,M): # 열의 등차
                S = ""
                x,y = i,j
                if row_d == 0 and col_d == 0:
                    continue
                while 0 <= x < N and 0 <= y < M:
                    S += board[x][y]
                    if sqr(S):
                        answer = max(answer,int(S))
                    x += row_d
                    y += col_d
print(answer)