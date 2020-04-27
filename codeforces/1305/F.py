import random
n = int(input())
a = [int(x) for x in input().split()]
can = set()
ls = []
for i in range(10):
    idx = random.randint(0, n - 1)
    for c in range(-1, 2):
        if a[idx] + c > 0: ls.append(a[idx] + c)

maxn = 1000001
prime = []
vis = [True] * maxn
for i in range(2, maxn):
    if vis[i] is not True: continue
    if i * i > maxn: break
    for j in range(i * i, maxn, i):
        vis[j] = False

for i in range(2, maxn):
    if vis[i]: prime.append(i)

for val in ls:
    i = 2
    for i in prime:
        if i * i > val: break
        div = False
        while val % i == 0:
            val //= i
            div = True
        if div: can.add(i)
        i = i + 1
    if val is not 1: can.add(val) 

ans = n
for i in can:
    total = 0
    for j in a: 
        if j >= i: total += min(j % i, i - (j % i))
        else: total += i - j
    ans = min(ans, total)

print(ans)
