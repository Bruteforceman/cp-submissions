import math
import sys
n = int(input())
a = [int(_) for _ in input().split()]
maxPrime = int(1e7) + 1
comp = [1] * maxPrime
for i in range(2, maxPrime):
    if comp[i] != 1: continue
    for j in range(i * i, maxPrime, i):
        comp[j] = i
d1 = []
d2 = []
for i in a:
    val, div = 1, comp[i]
    tmp = i
    while div > 1 and i % div == 0:
        i = i // div
        val = val * div
    nval = tmp // val
    if val == 1 or val == tmp: val = -1
    if nval == 1 or nval == tmp: nval = -1
    d1.append(val)
    d2.append(nval)
print(' '.join(map(str, d1)))
print(' '.join(map(str, d2)))
