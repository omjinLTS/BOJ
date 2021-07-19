a,b,c=map(int,input().split())
d=0
while a:
    d+=1
    print(f'Triangle #{d}')
    if a<0:n,s = c**2 - b**2,'a'
    elif b<0:n,s = c**2 - a**2,'b'
    else: n,s = a**2 + b**2,'c'
    if n < 1:
        print("Impossible.")
    else:
        print(s,'=',format(n**0.5, '.03f'))
    print()
    a,b,c=map(int,input().split())