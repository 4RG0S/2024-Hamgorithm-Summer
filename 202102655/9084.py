# 9084번 - 동전

N, M = map(int, input().split())

memoryList = [0] + [int(x) for x in input().split()]
costList = [0] + [int(x) for x in input().split()]

backpack = [[0] * (sum(costList) + 1) for _ in range(N + 1)]

answer = sum(costList)

for i in range(1, N + 1):
    for j in range(1, sum(costList) + 1):
        if j < costList[i]:
            backpack[i][j] = backpack[i - 1][j]

        else:
            backpack[i][j] = max(
                backpack[i - 1][j], backpack[i - 1][j - costList[i]] + memoryList[i]
            )

        if backpack[i][j] >= M:
            answer = min(answer, j)

print(answer)
