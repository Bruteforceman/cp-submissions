import math
import sys
k = int(input())
s = 'codeforces'
opt = s * 100
for i in range(1, 100):
    for j in range(len(s) + 1):
        if pow(i, j) * pow(i + 1, len(s) - j) >= k:
            t = ''
            cnt = [i] * j + [i + 1] * (len(s) - j)
            for x in range(len(s)):
                t += s[x] * cnt[x]
            if len(opt) >= len(t):
                opt = t
print(opt)
