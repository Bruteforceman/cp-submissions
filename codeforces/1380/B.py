import math
import sys
input = sys.stdin.readline
t = int(input())
for cs in range(t):
    s = input().strip()
    d = {'R': 0, 'P' : 0, 'S' : 0}
    for i in s:
        d[i] = d[i] + 1
    win = {'R' : 'P', 'P' : 'S', 'S' : 'R'}
    cnt, opt = max([(value, key) for key, value in d.items() ])
    print(win[opt] * len(s))
