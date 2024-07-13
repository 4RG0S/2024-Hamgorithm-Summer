# 14659 - 한조서열정리하고옴ㅋㅋ

n = int(input())
data = list(map(int, input().split()))
 
height = data[0]
ans = []
count = 0
 
for i in range(1, n):
  if data[i] < height:
    count += 1
  else:
    height = data[i]
    ans.append(count)
    count = 0
  
ans.append(count) # 내림차순으로 정렬된 경우
print(max(ans))