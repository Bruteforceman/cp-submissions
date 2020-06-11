import math
import sys
input = sys.stdin.readline

t = int(input())
for cs in range(t):
    n, x, m = map(int, input().split())
    l, r = x, x
    for i in range(m):
        p, q = map(int, input().split())
        if r < p or q < l: continue
        l = min(l, p)
        r = max(r, q)
    print(r - l + 1)
