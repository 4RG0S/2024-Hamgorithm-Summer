import sys
input = sys.stdin.readline

def dfs(node, tree):
    tree[node] = -2
    for i in range(len(tree)):
        if tree[i] == node:
            dfs(i, tree)

n = int(input())
tree = list(map(int, input().split()))
delete_node = int(input())

dfs(delete_node, tree)

leaf_count = 0
for i in range(n):
    if tree[i] != -2 and i not in tree:
        leaf_count += 1

print(leaf_count)
