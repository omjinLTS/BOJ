import sys
input = sys.stdin.readline

def dfs(g, y, x):
    dx = 1, 0, -1, 0
    dy = 0, 1, 0, -1
    if x<0 or x>=M or y<0 or y>=N:
        return False
    if g[y][x]:
        g[y][x] = 0
        for i in range(4):
            dfs(g, y+dy[i],  x+dx[i])
        return True
    return False

for _ in range(int(input())):
    M, N, K = map(int, input().split())
    graph = [[0]*M for __ in range(N)]
    for __ in range(K):
        X, Y = map(int, input().split())
        graph[Y][X] = 1
    cnt = 0
    for x in range(M):
        for y in range(N):
            if dfs(graph, y, x):
                cnt += 1
    print(cnt)