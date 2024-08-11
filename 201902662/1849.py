import sys
input = sys.stdin.readline

def main():
    n = int(input())
    tree = [0 for _ in range(4*n)]
    seq = [0 for _ in range(n+1)]
    
    def insert(num, val):
        
        def intervalInsert(start, end, idx, val):
            
            if start == end:
                seq[start] = num
                tree[idx] += 1
                return
                
            mid = (start+end)//2
            leftVal = (end-start)//2 - tree[idx*2] + 1
            if leftVal > val:
                intervalInsert(start, mid, idx*2, val)
            else:
                intervalInsert(mid+1, end, idx*2+1, val-leftVal)
            tree[idx] += 1
            
        intervalInsert(1, n, 1, val)
    
    for i in range(1, n+1):
        insert(i, int(input()))
    
    for i in range(1, n+1):
        print(seq[i])
    
if __name__ == "__main__":
    main()