n = int(input()) + 1
cnt = 0
for i in range(1, n):
    for j in range(i, n):
        if i*j < n:
            cnt += 1
print(cnt)