import sys
import math
input = sys.stdin.readline
n = int(input())
a = [int(_) for _ in input().split()]
ans = 0
for i in range(n):
    for j in range(i, n):
        for k in range(j, n):
            ans = max(ans, a[i] | a[j] | a[k])
print(ans)
