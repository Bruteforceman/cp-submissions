import math
import sys
input = sys.stdin.readline
n = int(input())
def isPrime(n):
    for i in range(2, n):
        if n % i == 0:
            return False
    return True
if isPrime(n):
    print('YES')
    print('\n'.join(list(map(str, [1] + [i * pow(i - 1, n - 2, n) % n for i in range(2, n)] + [n]))[:n]))
elif n == 4:
    print('YES')
    print('\n'.join(map(str, [1, 3, 2, 4])))
else:
    print('NO')
