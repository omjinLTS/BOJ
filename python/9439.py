while(1):
    M, A, B = map(int, input().split())
    if not M+A+B:
        break
    T = round(3600*M*(1/A-1/B))
    print("{0}:{1:02}:{2:02}".format(T//3600, T%3600//60, T%60))