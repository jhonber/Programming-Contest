# http://codeforces.com/contest/592/problem/C

from fractions import gcd

readLine = raw_input
readArgs = lambda : readLine().split()
readInts = lambda : map(int, readArgs())
readInt = lambda : readInts()[0]

def lcm (a, b):
    return a / gcd(a, b) * b

def solve (t, w, b):
    l = lcm(w, b)
    x = t / l

    ans = 0;
    first = min(t, min(w, b) - 1)
    ans += first

    if (l <= t):
        t2 = t - (l * x)
        last = min(t2, min(w, b) - 1)
        ans += last

    if (t >= l):
        ans = ans + 1

    if (x > 0):
        ans += x - 1
        ans += first * (x - 1)

    k = gcd(ans, t)
    ans /= k
    t /= k


    print ("%i/%d") % (ans, t);


t,w,b = readInts()
solve(t, w, b)