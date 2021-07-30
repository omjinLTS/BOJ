T = input()
P = input()

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

#KMP
def kmp(T, P):
    n, m, j = len(T), len(P), 0
    result = []
    pi = getPi(P)
    for i in range(n):
        while j > 0 and T[i] != P[j]:
            j = pi[j-1]
        if T[i] == P[j]:
            if j == m-1:
                result.append(i-m+1)
                j = pi[j]
            else:
                j+=1
    return result 
result = kmp(T, P)
print(len(result))
print(*result)