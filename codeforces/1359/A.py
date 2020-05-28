import math
import sys
input = sys.stdin.readline

t = int(input())
res = []
def ceiling(p, q):
    return (p + q - 1) // q
for cs in range(t):
    n, m, k = map(int, input().split())
    maxJoker = min(m, n // k)
    minJoker = ceiling(m - maxJoker, k - 1)
    res.append(maxJoker - minJoker)
print('\n'.join(map(str, res)))
