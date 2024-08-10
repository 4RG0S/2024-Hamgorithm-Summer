def main():
    n = int(input())
    score = list(map(int, input().split()))
    
    dp = [[[0, 0, 0] for _ in range(n)] for _ in range(n)]
    
    for i in range(n):
        dp[i][i] = [0, score[i], score[i]]
    
    for i in range(n):
        for j in range(i+1, n):
            dp[i][j][1] = min(dp[i][j-1][1], score[j])
            dp[i][j][2] = max(dp[i][j-1][2], score[j])
            dp[i][j][0] = dp[i][j][2] - dp[i][j][1]
    
    result = [0 for _ in range(n)]
    
    for i in range(1, n):
        result[i] = dp[0][i][0]
        for j in range(1, i):
            result[i] = max(result[i], result[j-1]+dp[j][i][0])
    
    print(result[-1])
    
if __name__ == "__main__":
    main()