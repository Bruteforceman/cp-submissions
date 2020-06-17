import math
import sys
input = sys.stdin.readline

n = int(input())
a = [int(_) - 1 for _ in input().split()]
vis = [False] * n
cycles = [[] for _ in range(n + 1)]
for i in range(n):
    if vis[i]: continue
    cur = i
    cycle = []
    while not vis[cur]:
        vis[cur] = True
        cycle.append(cur)
        cur = a[cur]
    cycles[len(cycle)].append(cycle)
p = [0] * n
for i in range(n + 1):
    if i % 2 == 1:
        for j in cycles[i]:
            for k in range(i):
                p[j[k]] = j[(k + (i + 1) // 2) % i]
    else:
        if len(cycles[i]) % 2 == 1:
            print(-1)
            exit(0)
        for j in range(0, len(cycles[i]), 2):
            for k in range(i):
                p[cycles[i][j][k]] = cycles[i][j + 1][k] 
                p[cycles[i][j + 1][k]] = cycles[i][j][(k + 1) % i]
print(' '.join(map(lambda i : str(i + 1), p)))
