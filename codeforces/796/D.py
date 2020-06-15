import math
import sys
input = sys.stdin.readline
inf = int(1e9)
n, m, d = map(int, input().split())
l = [0] * (n - 1)
r = [0] * (n - 1)
g = [[] for _ in range(n)]

station = [int(_) - 1 for _ in input().split()]
for i in range(n - 1):
    l[i], r[i] = map(lambda i : int(i) - 1 , input().split())
    g[l[i]].append(i)
    g[r[i]].append(i)

queue = []
dist = [inf] * n
need = [True] * (n - 1)
for i in station:
    queue.append(i)
    dist[i] = 0
cur = 0
while cur < len(queue):
    x, cur = queue[cur], cur + 1
    for edge in g[x]:
        y = l[edge] ^ r[edge] ^ x
        if dist[y] > 1 + dist[x]:
            dist[y] = 1 + dist[x]
            queue.append(y)
            need[edge] = False
print(sum(need))
edgeList = []
for i in range(n - 1):
    if need[i]:
        edgeList.append(str(i + 1))
print(' '.join(edgeList))
