from collections import Counter as c
exec('''a,b=input().split();d=""if c(a)==c(b)else"NOT ";print(f'{a} & {b} are {d}anagrams');'''*int(input()))