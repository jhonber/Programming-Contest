# http://codeforces.com/contest/305/problem/B

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

def gcd(a,b):
    if(b == 0):
        return a
    else:
        return gcd(b,a % b)

def f(f1,f2):
    a = f2[1]
    b = (f1[0]*f2[1]) + f2[0]
    k = gcd(a,b)
    return [a/k, b/k]

def solve():
    frac = [1,v[n-1]]
    for i in range(n-2,-1,-1):
        frac = f([v[i],1],frac)

    k = gcd(p,q)
    if ((frac[0] == q/k and frac[1] == p/k)):
        print "YES"
    else:
        print "NO"

p,q = readInts()
n = readInt()
v = readInts()

solve()