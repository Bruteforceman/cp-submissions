import math
import sys
input = sys.stdin.readline
result = []
for i in range(int(input())):
    a = int(input())
    result.append('YES' if a % 4 == 0 else 'NO')
print('\n'.join(result))
