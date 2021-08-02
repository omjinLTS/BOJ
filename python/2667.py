from typing import Counter


dx = 0, 0, 1, -1
dy = 1, -1, 0, 0

n = int(input())
graph = [[*map(int, [*input()])] for _ in range(n)]
cnt = 0

def dfs(x, y):
    global cnt
    cnt+=1
    graph[x][y] = 0
    for i in range(4):
        nx, ny = x+dx[i], y+dy[i]
        if nx < 0 or nx >= n or ny < 0 or ny >= n:
            continue
        if graph[nx][ny]:
            dfs(nx, ny)
    return cnt
towns = []

for i in range(n):
    for j in range(n):
        if graph[i][j]:
            cnt = 0
            dfs(i, j)
            towns.append(cnt)

print(*[len(towns),*sorted(towns)], sep='\n')