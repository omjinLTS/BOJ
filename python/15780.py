n, k = map(int, input().split())
multiTap = map(int, input().split())
count = 0
for m in multiTap:
    count += (m+1)//2
print("YNEOS"[count<n::2])