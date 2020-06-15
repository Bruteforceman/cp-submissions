import math
import sys
input = sys.stdin.readline
t = int(input())
def toDecimal(x):
    value = 0
    for i in x:
        value = 2 * value + ord(i) - ord('0')
    return value
def toBinary(x, m):
    s = ''
    for i in range(m):
        s += str(x % 2)
        x = x // 2
    return s[::-1]
result = []
for case in range(t):
    n, m = map(int, input().split())
    a = []
    for i in range(n):
        a.append(toDecimal(input().strip()))
    a.sort()
    l, r = 0, 2**m
    position = (r - n - 1) // 2
    while l < r:
        mid = (l + r + 1) // 2
        cnt = mid
        for i in a:
            if i < mid:
                cnt = cnt - 1
        if position >= cnt:
            l = mid
        else:
            r = mid - 1
    result.append(toBinary(l, m))
print('\n'.join(result))
