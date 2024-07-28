# 너의 평점은
import sys
point = {"A+" : 4.5, "A0": 4.0, "B+": 3.5, "B0" : 3.0, "C+" : 2.5, "C0":2.0, "D+":1.5, "D0":1.0, "F": 0.0}
allPoint = 0
allPointofGradient = 0
for i in range(20):
    a = list(map(str, sys.stdin.readline().split()))
    if (a[2] != 'P'):
        allPoint += float(a[1])
        allPointofGradient += float(a[1]) * point[a[2]]
print(allPointofGradient/allPoint)