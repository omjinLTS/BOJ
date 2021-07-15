a, b = input().split()
a, b = int(a), int(b+a)

isPrime = [True for i in range(b + 1)]
for i in range(2, int(b**0.5)+1):
    if isPrime[i]:
        for j in range(2*i, b+1, i):
            isPrime[j] = False
if isPrime[a] and isPrime[b]:
    print('Yes')
else:
    print('No')