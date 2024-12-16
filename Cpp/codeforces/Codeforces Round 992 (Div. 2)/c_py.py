import bisect
import heapq
import math
import sys

input = lambda: sys.stdin.readline()
from collections import defaultdict, deque

t = 1
t = int(input())

for _ in range(t):
    n, k = map(int, input().split())
    if k > pow(2, n - 1):
        print(-1)
        continue
    if k == 1:
        print(*range(1, n + 1))
        continue
    k -= 1
    ans = [0] * (n + 1)
    i = 1
    j = n
    x = 1
    for mo in range(n - 2, -1, -1):
        if (k >> mo) & 1:
            ans[j] = x
            j -= 1
        else:
            ans[i] = x
            i += 1
        x += 1

    for i in range(1, n + 1):
        if ans[i] == 0:
            ans[i] = x
        print(ans[i], end=" ")
    print()
