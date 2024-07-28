# K번째 수
def find_kth_number(N, k):
    low, high = 1, N * N

    while low < high:
        mid = (low + high) // 2
        count = 0

        for i in range(1, N + 1):
            count += min(mid // i, N)

        if count < k:
            low = mid + 1
        else:
            high = mid

    return low


# 입력 받기
N = int(input())
k = int(input())

# 결과 출력
print(find_kth_number(N, k))
