N, M = map(int, input().split())
L = sorted([*map(int, input().split())])
a = []

def dfs(depth):
    if depth == M:
        print(' '.join(map(str, a)))
        return
    for i in range(N):
        if depth == 0 or a[depth-1] <= L[i]:
            a.append(L[i])
            dfs(depth+1)
            a.pop()
dfs(0)