import sys
input = sys.stdin.readline

def main():
    n, m = map(int, input().split())
    nums = list(map(int, input().split()))
    
    sums = [nums[0] % m]
    for i in range(1, n):
        sums.append((sums[i-1] + nums[i]) % m)
        
    divs = [0 for _ in range(m)]
    for i in sums:
        divs[i] += 1
    
    result = divs[0]
    for i in divs:
        if i < 2:
            continue
        result += (i * (i - 1)) // 2
    
    print(result)
    
if __name__ == "__main__":
    main()