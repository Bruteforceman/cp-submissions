import math
import sys
input = sys.stdin.readline
def query(a):
    if len(a) == 0:
        return 0
    print('?', len(a), ' '.join(map(str, a)))
    sys.stdout.flush()
    return int(input())
n = int(input())
maxQ = 13
mask = []
for i in range(1 << maxQ):
    cnt = 0
    for j in range(maxQ):
        if ((i >> j) & 1):
            cnt = cnt + 1
    if cnt == (maxQ // 2):
        mask.append(i)
queries = [[] for _ in range(maxQ)]
values = []
for i in range(1, n + 1):
    for j in range(maxQ):
        if ((mask[i] >> j) & 1):
            queries[j].append(i)
for i in queries:
    values.append(query(i))
password = []
for i in range(1, n + 1):
    val = 0
    for j in range(maxQ):
        if ((mask[i] >> j) & 1) == 0:
            val = val | values[j]
    password.append(val)
print('!', ' '.join(map(str, password)))
sys.stdout.flush()
