import math
import sys
t = int(input())
result = []
for cs in range(t):
    n, k = map(int, input().split())
    a = [[0] * n for _ in range(n)]
    result.append('0' if k % n == 0 else '2')
    for i in range(n):
        cur = 0
        while cur < n and k > 0:
            a[cur][(i + cur) % n] = 1
            k -= 1
            cur += 1
    for i in range(n):
        result.append(''.join(map(str, a[i])))
print('\n'.join(result))


