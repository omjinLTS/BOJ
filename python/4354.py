import sys
input = sys.stdin.readline

def getPi(p):
    pi, j = [0]*len(p), 0
    for i in range(1, len(p)):
        while j > 0 and p[i] != p[j]:
            j = pi[j-1]
        if p[i] == p[j]:
            j+=1
            pi[i] = j
    return pi

while 1:
    p = input().rstrip()
    if p=='.': break
    pi = getPi(p)
    c = len(p)-pi[-1]
    print(1 if len(p)%c else len(p)//c)