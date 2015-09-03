# http://codeforces.com/contest/71/problem/B

import sys
import math
from fractions import Fraction

si = sys.stdin
so = sys.stdout
se = sys.stderr

readLine = raw_input
readArgs = lambda : readLine().split()
readInts = lambda : map(int, readArgs())
readInt = lambda : readInts()[0]


n,k,t = readInts()
t = t*1.0

a = 100.0/n
b = a/k
v = []

for i in range(0,101):
    v.append(0)

tot = 0.0
acum = 0.0

for i in range(0,n):
    f = True;
    for j in range(0,k):
        if (tot+b > t and (acum+1)*b > t):
            f = False
            break
        acum = acum + 1
        v[i] = v[i] + 1
        tot = tot + b
    if ( not f):
        break

for i in range(0,n):
    print v[i],
