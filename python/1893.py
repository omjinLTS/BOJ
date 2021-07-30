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

def kmpCount(T, P):
    n, m, j = len(T), len(P), 0
    result = 0
    pi = getPi(P)
    for i in range(n):
        while j > 0 and T[i] != P[j]:
            j = pi[j-1]
        if T[i] == P[j]:
            if j == m-1:
                result += 1
                j = pi[j]
            else:
                j+=1
    return result    

for _ in range(int(input())):
    A = input().rstrip()[::-1]
    W = input().rstrip()
    S = input().rstrip()

    shift = {A[i]:A[(i+1)%len(A)] for i in range(len(A))}
    unique = []

    for i in range(len(A)):
        if kmpCount(S, W) == 1:
            unique.append(i)
        S = ''.join([shift[c] for c in S])
    
    if len(unique)<1:
        print('no solution')
    else:
        print('unique:' if len(unique)==1 else 'ambiguous:',*unique)