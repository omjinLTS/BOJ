s=input()
jc = ic = 0
for i in range(len(s)-2):
    if s[i:i+3] == 'JOI': jc+=1
    if s[i:i+3] == 'IOI': ic+=1

print(jc,ic,sep='\n')