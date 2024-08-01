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
    
    bfs_seq = deque(list(map(int, input().split())))
    que = deque()
    
    if bfs_seq[0] == 1:
        que.append(bfs_seq.popleft())
    
    while len(que):
        node = que.popleft()
        while len(bfs_seq) and bfs_seq[0] in tree[node]:
            que.append(bfs_seq.popleft())
    
    if len(bfs_seq) == 0:
        print(1)
    else:
        print(0)
    
if __name__ == "__main__":
    main()