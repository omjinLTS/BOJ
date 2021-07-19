c = lambda a,b:a%(10**b)//(10**(b-1))
while 1:
    a,b=sorted(map(int, input().split()))
    d=e=0
    if a+b==0: break
    for i in range(1, b+1):
        if c(a,i)+c(b,i)+d>9:
            e+=1
            d+=1
        else: d=0
    print(e)
