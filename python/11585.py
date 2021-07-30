from math import gcd

N = int(input())
T = input().replace(' ','')
P = input().replace(' ','')

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

cnt = N // (N - getPi(P)[-1])

k=gcd(cnt, N)
print(f'{cnt//k}/{N//k}')