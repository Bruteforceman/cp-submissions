import math
import sys
input = sys.stdin.readline
n, m = map(int, input().split())
a = [[] for _ in range(n)]
for i in range(n):
    a[i] = [int(_) for _ in input().split()]
row = []
col = []
rowStat = [1] * n
colStat = [1] * m
while True:
    bad = False
    for i in range(n):
        total = 0
        for j in range(m):
            total += a[i][j]
        if total < 0:
            bad = True
            rowStat[i] *= -1
            for j in range(m):
                a[i][j] *= -1
    for i in range(m):
        total = 0
        for j in range(n):
            total += a[j][i]
        if total < 0:
            bad = True
            colStat[i] *= -1
            for j in range(n):
                a[j][i] *= -1
    if not bad:
        break
for i in range(n):
    if rowStat[i] == -1:
        row.append(i + 1)
for i in range(m):
    if colStat[i] == -1:
        col.append(i + 1)
print(len(row), ' '.join(map(str, row)))
print(len(col), ' '.join(map(str, col)))
