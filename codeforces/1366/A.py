import sys
import math
input = sys.stdin.readline
t = int(input())
for cs in range(t):
    a, b = map(int, input().split())
    print(min((a + b) // 3, a, b))
