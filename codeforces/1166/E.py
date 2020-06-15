import math
import sys
input = sys.stdin.readline
m, n = map(int, input().split())
a = []
for i in range(m):
    shops = tuple(map(lambda i : int(i) - 1, input().split()))
    a.append(shops[1:])

for i in range(m):
    for j in range(i):
        vis = [False] * n
        common = 0
        for k in a[i]:
            vis[k] = True
        for k in a[j]:
            common += vis[k]
        if common == 0:
            print('impossible')
            exit(0)
print('possible')
