input()
s=[*map(int, input().split())]
for i in range(1,max(s)+1):
 c=1
 for n in s:
  if n%i:
   c=0
   break
 if c:print(i)