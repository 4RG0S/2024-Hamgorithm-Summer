import heapq
import sys
input = sys.stdin.readline

def main():
    n = int(input())
    li = [0] + list(map(int, input().split()))
    
    que = []
    for i in range(1, n+1):
        heapq.heappush(que, (li[i], i))
    
    m = int(input())
    for _ in range(m):
        query = list(map(int, input().split()))
        if query[0] == 1:
            li[query[1]] = query[2]
            heapq.heappush(que, (query[2], query[1]))
        else:
            while True:
                v, i  = heapq.heappop(que)
                if li[i] != v:
                    continue
                heapq.heappush(que, (v, i))
                print(i)
                break
                
if __name__ == "__main__":
    main()