# 뱀

from collections import deque

n = int(input())
k = int(input())
board = [[0] * n for _ in range(n)]
for _ in range(k):
    a, b = map(int, input().split())
    board[a-1][b-1] = 1

l = int(input())
directions = []
for _ in range(l):
    t, d = map(str, input().split())
    directions.append((int(t), d))

dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]
direction = 0
x, y = 0, 0
time, idx = 0, 0
snake = deque([(x, y)])

while True:
    x += dx[direction]
    y += dy[direction]
    time += 1

    if x < 0 or x >= n or y < 0 or y >= n or (x, y) in snake:
        break

    snake.append((x, y))

    if board[x][y] == 0:
        snake.popleft()
    else:
        board[x][y] = 0

    if idx < len(directions) and time == directions[idx][0]:
        if directions[idx][1] == 'L':
            direction = (direction - 1) % 4
        else:
            direction = (direction + 1) % 4
        idx += 1

print(time)
