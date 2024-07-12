import sys
# 물품의 수 N(1 ≤ N ≤ 100)과 준서가 버틸 수 있는 무게 K(1 ≤ K ≤ 100,000
N, K = map(int, sys.stdin.readline().split())
bag = [0] * (K+1)

# 물건의 무게, 가치
temp_DP = []
for i in range(N):
    a,b = map(int, sys.stdin.readline().split())
    temp_DP.append((a,b))

for w,v in temp_DP:
    for num in range(K, w-1, -1):
        bag[num] = max(bag[num], v+bag[num-w])
    # print(bag)
print(bag[K])