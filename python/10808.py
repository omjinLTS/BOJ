a=[0]*(ord('z')+1)
for c in input():a[ord(c)]+=1
print(*a[ord('a'):ord('z')+1])