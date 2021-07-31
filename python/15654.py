N, M = map(int, input().split())
L = sorted([*map(int, input().split())])
visited = [False] * N
a = []

def dfs(depth, N, M):
    if depth == M:
        print(' '.join(map(str, a)))
        return
    for i in range(N):
        if not visited[i]:
            visited[i] = True
            a.append(L[i])
            dfs(depth+1, N, M)
            a.pop()
            visited[i] = False
dfs(0, N, M)