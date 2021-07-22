squares = [i**2 for i in range(223)]
n = int(input())
dp = [5 for _ in range(n+1)]
dp[1] = 1
for i in range(2, n+1):
    for s in squares:
        if i == s:
            dp[i] = 1
            break
        if s > i:
            break
        dp[i] = min(dp[i], dp[i-s]+1)
print(dp[n])