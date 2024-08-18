import sys
input = sys.stdin.readline
inf = float("inf")

def main():
    n, m = map(int, input().split())
    city = [list(map(int, input().split())) for _ in range(n)]    
    
    home = []
    chick = []
    
    for r in range(n):
        for c in range(n):
            if city[r][c] == 1:
                home.append((r, c))
            elif city[r][c] == 2:
                chick.append((r, c))

    dist = [[] for _ in range(len(chick))]
    for i in range(len(chick)):
        for j in range(len(home)):
            dist[i].append(abs(chick[i][0]-home[j][0]) + abs(chick[i][1]-home[j][1]))
    
    def rec(num, idx, cnt):
        
        if cnt == m:
            val = 0
            for i in range(len(home)):
                crnt = inf
                for j in num:
                    crnt = min(crnt, dist[j][i])
                val += crnt
            return val
        
        elif cnt < m:
            val = inf
            for i in range(idx, len(chick)):
                val = min(val, rec(num+[i], i+1, cnt+1))
            return val

        else:
            return inf
    
    print(rec([], 0, 0))

if __name__ == "__main__":
    main()