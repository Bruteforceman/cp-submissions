import math
import sys
input = sys.stdin.readline
n = int(input())
if math.factorial(n - 1) % n == n - 1:
    print('YES')
    print('\n'.join(list(map(str, [1] + [i * pow(i - 1, n - 2, n) % n for i in range(2, n)] + [n]))[:n]))
elif n == 4:
    print('YES')
    print('\n'.join(map(str, [1, 3, 2, 4])))
else:
    print('NO')
