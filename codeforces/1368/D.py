import math
import sys
input = sys.stdin.readline
n = int(input())
a = [int(x) for x in input().split()]
maxBit = 30
cnt = [0] * maxBit
for i in a:
    for j in range(maxBit):
        if ((i >> j) & 1):
            cnt[j] += 1
b = [0] * n
for i in range(maxBit):
    for j in range(cnt[i]):
        b[j] += (1 << i)
ans = 0
for i in b:
    ans += i * i
print(ans)

