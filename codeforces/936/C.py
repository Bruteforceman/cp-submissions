import math
import sys
input = sys.stdin.readline
result = []
def move(s, x):
    result.append(x)
    # print(s[-1:-1-x:-1] + s[:len(s) - x])
    return s[-1:-1-x:-1] + s[:len(s) - x]
def getFirst(s, need, size):
    piv = -1
    for i in range(size, len(s)):
        if s[i] == need:
            piv = i
            break
    if piv == -1:
        print(-1)
        exit(0)
    s = move(s, len(s) - piv)
    s = move(s, piv - size)
    s = move(s, size + 1)
    return s
n = int(input())
s = input().strip()
t = input().strip()
l, r = len(s) // 2, len(s) // 2
s = getFirst(s, t[l], 0)
size = 1
while size < len(s):
    if size % 2 == 1:
        l = l - 1
        s = getFirst(s, t[l], size)
    else:
        r = r + 1
        s = getFirst(s, t[r], size)
    size = size + 1
    # print(s)
if s != t:
    s = move(s, len(s))
# print(s)
print(len(result))
print(' '.join(map(str, result)))
