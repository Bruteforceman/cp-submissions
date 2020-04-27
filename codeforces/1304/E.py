n = int(input())
g = [[] for _ in range(n)]
for i in range(n - 1):
    u, v = map(int, input().split())
    g[u - 1].append(v - 1)
    g[v - 1].append(u - 1)

logn = 19
st = [0] * n
dep = [-1] * n
par = [[0] * n for _ in range(logn + 1)]

st[0], cur = 0, 1
dep[0] = 0
while cur > 0: 
    x = st[cur - 1]
    cur = cur - 1
    for i in g[x]:
        if dep[i] is -1:
            dep[i] = 1 + dep[x]
            par[0][i] = x
            st[cur] = i
            cur = cur + 1

for i in range(1, logn + 1):
    for j in range(n):
        par[i][j] = par[i - 1][par[i - 1][j]]

def lca(i, j):
    if dep[i] > dep[j]:
        return lca(j, i)
    var = logn
    while var >= 0: 
        if dep[j] - (1 << var) >= dep[i]:
            j = par[var][j]
        var = var - 1
    if i == j: return i
    var = logn
    while var >= 0:
        if par[var][i] is not par[var][j]:
            i = par[var][i]
            j = par[var][j]
        var = var - 1
    return par[0][i]

def dist(i, j):
    return dep[i] + dep[j] - 2 * dep[lca(i, j)]


def query(a, b, x, y, k):
    can = []
    can.append(dist(x, y))
    can.append(dist(x, a) + 1 + dist(b, y))
    can.append(dist(x, b) + 1 + dist(a, y))
    for i in can: 
        if i % 2 == k % 2 and i <= k:
            return 'YES'
    return 'NO'

q = int(input())
res = []
for i in range(q):
    x, y, a, b, k = map(int, input().split())
    res.append(query(x - 1, y - 1, a - 1, b - 1, k))
print('\n'.join(res))
