K = int(input()) - 1
N = int(input())
ans = [input().split() for i in range(N)]
i = 0
time = 210
while 1:
    T, Z = ans[i]
    T = int(T)
    time -= T
    if time <= 0:
        print(K + 1)
        exit(0)
    if Z == 'T':
        K = (K + 1) % 8
    i += 1
