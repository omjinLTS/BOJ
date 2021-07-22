def dfs(s, idx, string, used):
    if idx == ln:
        print(''.join(string))
        return
    for c in Ss:
        if used[c] < s.count(c):
            used[c]+=1
            string[idx] = c
            dfs(s, idx+1, string, used)
            used[c]-=1

for _ in range(int(input())):
    s = sorted(input())
    Ss = set(s)
    ln = len(s)
    dfs(s, 0, ['' for i in range(ln)], {a:0 for a in Ss})