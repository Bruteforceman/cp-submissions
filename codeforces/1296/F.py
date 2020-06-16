import math
import sys
input = sys.stdin.readline
n = int(input())
g = [[] for _ in range(n)]
for i in range(n - 1):
    x, y = map(lambda i : int(i) - 1, input().split())
    g[x].append((y, i))
    g[y].append((x, i))
par = [-1] * n
parEdge = [-1] * n
dep = [0] * n
stack = [0]
par[0] = 0
while len(stack) > 0:
    cur = stack.pop()
    for node, edge in g[cur]:
        if par[node] == -1:
            dep[node] = 1 + dep[cur]
            par[node], parEdge[node] = cur, edge
            stack.append(node)
paths = []
m = int(input())
for i in range(m):
    a, b, f = map(int, input().split())
    paths.append((f, a - 1, b - 1))
paths.sort(reverse=True)


value = [-1] * (n - 1)
for f, a, b in paths:
    if dep[a] > dep[b]:
        a, b = b, a
    while dep[b] != dep[a]:
        if value[parEdge[b]] == -1:
            value[parEdge[b]] = f
        b = par[b]
    while a != b:
        if value[parEdge[a]] == -1:
            value[parEdge[a]] = f
        if value[parEdge[b]] == -1:
            value[parEdge[b]] = f
        a, b = par[a], par[b]
for i in range(n - 1):
    if value[i] == -1:
        value[i] = 1
for f, a, b in paths:
    if dep[a] > dep[b]:
        a, b = b, a
    ans = 100000000
    while dep[b] != dep[a]:
        ans = min(ans, value[parEdge[b]])
        b = par[b]
    while a != b:
        ans = min(ans, value[parEdge[a]], value[parEdge[b]])
        a, b = par[a], par[b]
    if ans != f:
        print(-1)
        exit(0)
print(' '.join(map(str, value)))
        

