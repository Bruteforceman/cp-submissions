import math
import sys
input = sys.stdin.readline
n, m = map(int, input().split())
w = [int(_) for _ in input().split()]
edges = []
g = [[] for _ in range(n)]
deg = [0] * n
for i in range(m):
    u, v = map(int, input().split())
    u, v = u - 1, v - 1
    g[u].append(v)
    g[v].append(u)
    edges.append((u, v))
    deg[u] += 1
    deg[v] += 1
order = [0] * n
done = [False] * n 
stack = []
cur = 0
for i in range(n):
    if deg[i] <= w[i]:
        done[i] = True
        order[i] = cur
        stack.append(i)
        cur += 1
while len(stack) > 0:
    x = stack.pop()
    for i in g[x]:
        deg[i] -= 1
        if not done[i] and deg[i] <= w[i]:
            order[i] = cur
            done[i] = True
            stack.append(i)
            cur += 1
if sum(done) != n:
    print('DEAD')
    exit(0)
sortEdges = []
for i in range(m):
    u, v = edges[i]
    if order[u] < order[v]:
        u, v = v, u
    sortEdges.append((order[u], order[v], i))
print('ALIVE')
print(' '.join(map(lambda i : str(i[2] + 1), sorted(sortEdges, reverse=True))))
