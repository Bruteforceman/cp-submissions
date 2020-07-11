import math
import sys
input = sys.stdin.readline
t = int(input())
def lcm(a, b):
    return a * (b // math.gcd(a, b))
for cs in range(t):
    n = int(input())
    cur = 1
    ans, opt = n + 1, 0
    div = []
    while cur * cur <= n:
        if n % cur == 0:
            div.append(cur)
            if cur * cur != n:
                div.append(n // cur)
        cur += 1
    for i in div:
        if i == n: continue
        if ans > lcm(i, n - i):
            ans = lcm(i, n - i)
            opt = i
    print(opt, n - opt)

