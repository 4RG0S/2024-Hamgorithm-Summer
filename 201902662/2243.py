import sys
input = sys.stdin.readline

MIN_VALUE = 1
MAX_VALUE = 1000000

def main():
    n = int(input())
    tree = [0 for _ in range(MAX_VALUE*4)]
    
    def add(num, value):
        
        def intervalAdd(start, end, idx, num, value):
            
            if not (start <= num <= end):
                return
            
            tree[idx] += value
            
            if start == end:
                return
            
            mid = (start+end)//2
            intervalAdd(start, mid, idx*2, num, value)
            intervalAdd(mid+1, end, idx*2+1, num, value)
            
        intervalAdd(MIN_VALUE, MAX_VALUE, MIN_VALUE, num, value)
    
    def find(rank):
        
        def intervalFind(start, end, idx, rank):
            if start == end:
                return start
            
            mid = (start+end)//2
            if tree[idx*2] >= rank:
                return intervalFind(start, mid, idx*2, rank)
            else:
                return intervalFind(mid+1, end, idx*2+1, rank-tree[idx*2])
                
        return intervalFind(MIN_VALUE, MAX_VALUE, MIN_VALUE, rank)
    
    for _ in range(n):
        query = list(map(int, input().split()))
        
        if query[0] == 1:
            num = find(query[1])
            add(num, -1)
            print(num)
        else:
            add(query[1], query[2])
    
if __name__ == "__main__":
    main()