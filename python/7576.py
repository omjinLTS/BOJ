from collections import deque
import sys
input = sys.stdin.readline

dx = 0, 0, 1, -1
dy = 1, -1, 0, 0

n, m = map(int, input().split())
tomatoes = [[*map(int, input().split())] for _ in range(m)]
q = deque()

for i in range(m):
    for j in range(n):
        if tomatoes[i][j] == 1:
            q.append([i, j])


def bfs(x, y):
    global queue
    while q:
        x, y = q.popleft()
        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]
            if nx < 0 or nx >= m or ny < 0 or ny >= n:
                continue
            if tomatoes[nx][ny] == 0:
                tomatoes[nx][ny] = tomatoes[x][y] + 1
                q.append([nx, ny])


bfs(i, j)
cnt = 0
for line in tomatoes:
    for tomato in line:
        if tomato == 0:
            print(-1)
            exit(0)
        cnt = max(cnt, tomato)
print(cnt-1)