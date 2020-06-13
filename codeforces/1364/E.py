import math
import sys
from random import randint, shuffle
input = sys.stdin.readline
mem = dict()
def query(i, j):
    if i > j:
        i, j = j, i
    if mem.get((i, j), -1) == -1:
        print('?', i + 1, j + 1)
        sys.stdout.flush()
        mem[i, j] = int(input())
    return mem[i, j]
n = int(input())
index = [int(x) for x in range(n)]
shuffle(index)
can = index[0:2]
for i in index[2:]:
    can.append(i)
    piv = -1
    for j in range(3):
        if piv != -1:
            break
        prev, nxt = (j + 2) % 3, (j + 1) % 3
        if query(can[j], can[nxt]) > query(can[j], can[prev]):
            piv = nxt
        elif query(can[j], can[prev]) > query(can[j], can[nxt]):
            piv = prev
    can.remove(can[piv])
while len(can) > 1:
    idx = randint(0, n - 1)
    if idx == can[0] or idx == can[1]:
        continue
    if query(idx, can[0]) > query(idx, can[1]):
        can.remove(can[0])
    elif query(idx, can[1]) > query(idx, can[0]):
        can.remove(can[1])

answer = []
for i in range(n):
    if can[0] != i:
        answer.append(query(can[0], i))
    else:
        answer.append(0)
print('!', ' '.join(map(str, answer)))
sys.stdout.flush()
