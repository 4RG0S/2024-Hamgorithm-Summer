# 네 번째 점
import sys
ar = []

def find_fourth_point(points):
    x_coords = [point[0] for point in points]
    y_coords = [point[1] for point in points]

    x4 = 0
    y4 = 0

    for x in x_coords:
        if x_coords.count(x) == 1:
            x4 = x
            break

    for y in y_coords:
        if y_coords.count(y) == 1:
            y4 = y
            break

    return (x4, y4)

for i in range(3):
    a,b = list(map(int, sys.stdin.readline().split()))
    ar.append((a,b))
result = find_fourth_point(ar)

print(result[0], result[1])