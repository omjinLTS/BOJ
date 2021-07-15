for _ in range(int(input())):
    N, D = map(int, input().split())
    cnt = 0
    for __ in range(N):
        v, f, c = map(int, input().split())
        if D/v*c <= f:
            cnt += 1
    print(cnt)