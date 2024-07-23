import sys
input = sys.stdin.readline

MAX_VALUE = 1000000000

def main():
    n, m = map(int, input().split())
    data = [0]
    tree = [0 for _ in range(n*4)]
    
    def init():
        
        def intervalInit(start, end, idx):
            if start == end:
                tree[idx] = data[start]
                return tree[idx]
            
            mid = (start+end)//2
            left = intervalInit(start, mid, idx*2)
            right = intervalInit(mid+1, end, idx*2+1)
            
            tree[idx] = min(left, right)
            return tree[idx]
            
        intervalInit(1, n, 1)
        
    def find(left, right):
        
        def intervalFind(start, end, idx):
            
            if left > end or right < start:
                return MAX_VALUE
            
            if left <= start and end <= right:
                return tree[idx]
            
            mid = (start+end)//2
            leftValue = intervalFind(start, mid, idx*2)
            rightValue = intervalFind(mid+1, end, idx*2+1)
            return min(leftValue, rightValue)
        
        return intervalFind(1, n, 1)
    
    for _ in range(n):
        data.append(int(input()))
    
    init()
    
    for _ in range(m):
        a, b = map(int, input().split())
        print(find(a, b))
    
if __name__ == "__main__":
    main()