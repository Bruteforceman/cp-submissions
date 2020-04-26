n, m = map(int, input().split())
g = [[] for _ in range(n)]
for i in range(m):
    p, q = map(int, input().split())
    g[p - 1].append(q - 1)
    g[q - 1].append(p - 1)

comp = [-1] * n
def shortest(root):
    dist = [-1] * n
    q = [0] * n
    left, right = 0, 1
    q[left] = root
    dist[root] = 0
    good = True
    while left < right:
        x = q[left]
        left = left + 1
        for i in g[x]:
            if dist[i] is -1: 
                dist[i] = 1 + dist[x]
                q[right] = i
                right = right + 1
            elif dist[i] == dist[x]:
                good = False 
    far = 0
    for i in dist:
        if i > far: far = i
    return good, far, dist

arr = [0] * n
good = True
for i in range(n):
    _, opt, dist = shortest(i)
    if _ is False: good = False
    if comp[i] is -1: 
        for j in range(n):
            if dist[j] is not -1:
                comp[j] = i
    if arr[comp[i]] < opt: 
        arr[comp[i]] = opt

if good is False: print('-1')
else: print(sum(arr))

