from collections import deque

dx = 0, 0, 1, -1, 0, 0
dy = 1, -1, 0, 0, 0, 0
dz = 0, 0, 0, 0, 1, -1

M, N, H = map(int, input().split())
boxes = [[[*map(int, input().split())] for i in range(N)] for j in range(H)]

#bfs
q = deque()
for i in range(H):
    for j in range(N):
        for k in range(M):
            if boxes[i][j][k] == 1:q.append([i,j,k])

while q:
    x, y, z = q.popleft()
    for i in range(6):
        nx, ny, nz = x+dx[i], y+dy[i], z+dz[i]
        if nx<0 or ny<0 or nz<0 or nx>=H or ny>=N or nz>=M:
            continue
        if boxes[nx][ny][nz] == 0:
            boxes[nx][ny][nz] = boxes[x][y][z]+1
            q.append([nx, ny, nz])

cnt = 0
for i in range(H):
    for j in range(N):
        for k in range(M):
            if boxes[i][j][k]:
                cnt = max(cnt, boxes[i][j][k])
            else:
                print(-1)
                exit(0)

print(cnt-1)