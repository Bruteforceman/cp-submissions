import math
import sys
input = sys.stdin.readline
n = int(input())
a = [int(_) for _ in input().split()]
for i in range(n):
    a[i] += i
a.sort()
for i in range(n):
    a[i] -= i
for i in range(n):
    if a[i] < 0 or (i > 0 and a[i - 1] > a[i]):
        print(':(')
        exit(0)
print(' '.join(map(str, a)))
