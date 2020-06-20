import math
import sys
input = sys.stdin.readline
t = int(input())
for i in range(t):
    n = int(input())
    a = [int(i) for i in input().split()]
    parity = [[], []]
    pairs = []
    for i in range(2 * n):
        parity[a[i] % 2].append(i + 1)
    for i in range(n - 1):
        for j in range(2):
            if len(parity[j]) >= 2:
                pairs.append((parity[j][-1], parity[j][-2]))
                parity[j].pop()
                parity[j].pop()
                break
    print('\n'.join(map(lambda i : str(i[0]) + ' ' + str(i[1]), pairs)))
