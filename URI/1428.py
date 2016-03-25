from math import *

n = int(raw_input())

for i in range(0, n):
    a, b = map(int, raw_input().split())
    print int(ceil((a - 2) / 3.0) * ceil((b - 2) / 3.0))