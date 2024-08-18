from collections import deque
import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

def main():
    n, r, q = map(int, input().split())
    tree = {i:[] for i in range(n+1)}
    
    for _ in range(n-1):
        u, v = map(int, input().split())
        tree[u].append(v)
        tree[v].append(u)
    
    visit = [False for _ in range(n+1)]
    visit[r] = True
    cost = [0 for _ in range(n+1)]
    
    def dfs(num):
        val = 1
        for v in tree[num]:
            if visit[v]:
                continue
            visit[v] = True
            dfs(v)
            val += cost[v]
        cost[num] = val
    dfs(r)
    
    for _ in range(q):
        print(cost[int(input())])
    
if __name__ == "__main__":
    main()