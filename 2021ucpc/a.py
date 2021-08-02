s=input()
for a,b in(1,-1),(1,-2),(1,-3),(2,-2),(2,-3),(3,-3):
 x,y=int(s[:a]),int(s[b:])
 if ''.join([str(i)for i in range(x,y+1)])==s:print(x,y);exit(0)