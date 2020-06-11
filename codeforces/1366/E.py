import sys
import math
input = sys.stdin.readline
n, m = map(int, input().split())
a = [int(i) for i in input().split()]
b = [int(i) for i in input().split()]
last = dict()
for i in range(n):
    last[a[i]] = i
prev = [0] * n
stack = []
for i in range(n):
    while len(stack) > 0 and a[stack[-1]] >= a[i]:
        stack.pop()
    prev[i] = -1 if len(stack) == 0 else stack[-1]
    stack.append(i)
suf = [0] * n
minVal = a[-1]
for i in range(n - 1, -1, -1):
    minVal = min(minVal, a[i])
    suf[i] = minVal
mod = 998244353
ans = 1 if min(a) == b[0] else 0  
for i in b:
    idx = last.get(i, -1)
    if idx == -1 or a[idx] > suf[idx]:
        ans = 0
    if i > b[0]:
        ans = ans * (idx - prev[idx])
    ans = ans % mod
print(ans)

