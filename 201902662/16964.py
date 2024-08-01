from collections import deque
import sys
input = sys.stdin.readline

def main():
    n = int(input())
    tree = {}
    
    for _ in range(n-1):
        node1, node2 = map(int, input().split())
        if node1 in tree:
            tree[node1].append(node2)
        else:
            tree[node1] = [node2]
        if node2 in tree:
            tree[node2].append(node1)
        else:
            tree[node2] = [node1]
    
    dfs_seq = deque(list(map(int, input().split())))
    
    def dfsVerify(num):
        while len(dfs_seq) and dfs_seq[0] in tree[num]:
            dfsVerify(dfs_seq.popleft())
    
    start = dfs_seq.popleft()
    if start == 1:
        dfsVerify(start)
    
    if len(dfs_seq) == 0:
        print(1)
    else:
        print(0)
    
if __name__ == "__main__":
    main()