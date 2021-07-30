s = [[*input()]for _ in range(5)]
ml = max([len(c) for c in s])
for c in s:
    while len(c)<ml:
        c.append('')
for s in zip(*s):print(*s,sep='',end='')