import sys
input = sys.stdin.readline

def getPi(p):
    m, j = len(p), 0
    pi = [0]*m
    for i in range(1, m):
        while j > 0 and p[i]!=p[j]:
            j = pi[j-1]
        if p[i] == p[j]:
            j+=1
            pi[i] = j
    return pi;


long = input().rstrip()
N = int(input())
shorts = []
shortsPi = []
for i in range(N):
    shorts.append(input().rstrip())
    shortsPi.append(getPi(shorts[i]))
dp = [0 for _ in range(len(long))]
check = [0 for _ in range(501)]

#kmp + dp
for i in range(len(long)):
    dp[i] = dp[i-1]
    for j in range(N):
        m = len(shorts[j])
        while check[j] > 0 and shorts[j][check[j]] != long[i]:
            check[j] = shortsPi[j][check[j]-1]
        if long[i] == shorts[j][check[j]]:
            if check[j] == m - 1:
                t = dp[i-m] if i-m>=0 else 0
                dp[i] = max(dp[i], t+m)
                check[j] = shortsPi[j][check[j]]
            else:
                check[j]+=1
print(dp[-1])