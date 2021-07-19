s=input()
n=''
while s!='=':
 n=n+s.replace('/','//') if s in'+-*/'else str(eval(n+s))
 s=input()
print(n)