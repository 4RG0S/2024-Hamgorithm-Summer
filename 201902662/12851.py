from collections import deque
max = 100001

def main():
    n, k = map(int, input().split())

    visit = [0 for _ in range(max)]
    que = deque([n])
    time, cnt = 0, 0
    
    while que:
        crnt = que.popleft()
        
        if crnt == k:
            time = visit[crnt]
            cnt += 1
            continue
        
        for next in [crnt-1, crnt+1, crnt*2]:
            if 0 <= next < max and (visit[next] == 0 or visit[next] == visit[crnt] + 1):
                visit[next] = visit[crnt] + 1
                que.append(next)
    
    print(time)
    print(cnt)
    
if __name__ == "__main__":
    main()