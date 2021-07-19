n = int(input())
m = int(input())
c = [eval(input().replace(*' -')) for _ in range(n)]
M = m
for i in c:
    m += i
    if m<0:
        M=0
        break
    M = max(M, m)
print(M)