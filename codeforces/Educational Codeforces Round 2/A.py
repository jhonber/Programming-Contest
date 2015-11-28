# http://codeforces.com/contest/600/problem/A

import sys

readLine = raw_input
readArgs = lambda : readLine().split()
readInts = lambda : map(int, readArgs())
readInt = lambda : readInts()[0]

s = raw_input()
s = s.replace(';', ',')
v = s.split(',')

a = []
b = []

for word in v:
    if (word.isdigit()):
        if (word[0] == '0' and len(word) > 1):
            b.append(word)
        else:
            a.append(word)
    else:
        b.append(word)


if (len(a) > 0):
    sys.stdout.write("\"")
    for i in range(0, len(a)):
        if (i > 0):
            sys.stdout.write(',')
        sys.stdout.write(a[i])

    sys.stdout.write("\"\n")
else:
    print "-"

if (len(b) > 0):
    sys.stdout.write("\"")
    for i in range(0, len(b)):
        if (i > 0):
            sys.stdout.write(',')
        sys.stdout.write(b[i])

    sys.stdout.write("\"")
else:
    print "-"