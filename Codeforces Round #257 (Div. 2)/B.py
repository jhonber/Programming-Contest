# http://codeforces.com/contest/450/problem/B

import sys
import math
import random as rd
from fractions import Fraction

si = sys.stdin
so = sys.stdout
se = sys.stderr

readLine = raw_input
readArgs = lambda : readLine().split()
readInts = lambda : map(int, readArgs())
readInt = lambda : readInts()[0]

MOD = 1000000007

x,y = readInts()
n = readInt()

if (n == 1):
    print x % MOD

elif (n == 2):
    print y % MOD

else:
    f = [x,y];
    f.append(f[1] - f[0])

    for i in range (3, 6):
        f.append( f[i-1] - f[i-2])

    print f[(n%6)-1] % MOD