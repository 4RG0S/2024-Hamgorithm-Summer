def main():
    n = int(input())
    data = list(map(int, input().split()))
    tree = [0 for _ in range(n*4)]
    ans = [0 for _ in range(n)]
    
    def insert(num):
        
        def intervalInsert(start, end, idx, value):
            
            tree[idx] += 1
            if start == end:
                ans[value-1] = num
                return
        
            mid = (start+end)//2
            if value-tree[idx*2+1] <= mid:
                intervalInsert(start, mid, idx*2, value-tree[idx*2+1])
            else:
                intervalInsert(mid+1, end, idx*2+1, value)
        
        intervalInsert(1, n, 1, n-data[num-1])
        
    for i in range(n, 0, -1):
        insert(i)
    
    print(*ans)
    
if __name__ == "__main__":
    main()