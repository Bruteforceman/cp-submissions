import math
import sys
t = int(input())
def isPrime(x):
    if x == 1: return False
    cur = 2
    while cur * cur <= x:
        if x % cur == 0: return False
        cur = cur + 1
    return True

for i in range(t):
    n = int(input())
    rem = n
    cnt = 0
    while rem % 2 == 0:
        cnt = cnt + 1
        rem = rem // 2
    if cnt > 1 or cnt == 0:
        if rem == 1:
            print('FastestFinger')
        else:
            print('Ashishgup')
    else:
        if isPrime(rem):
            print('FastestFinger')
        else:
            print('Ashishgup')
