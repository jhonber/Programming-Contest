from math import *

readLine = raw_input
readArgs = lambda : readLine().split()
readInts = lambda : map(int, readArgs())
readInt = lambda : readInts()

def read_int ():
    while (True):
        n = readInt()
        if (len(n) > 0):
            return n[0]

def read_ints ():
    while (True):
        v = readInts()
        if (len(v) > 0):
            return v

def solve (exp):
    print int(eval(exp))

while True:
    v = read_ints()
    r = v[0]
    c = v[1]

    if r == 0: break

    mat = []
    for i in range(0, r):
        line = readLine();
        mat.append(line)

    v = []
    for i in mat:
        v.append(len(i))

    if (r == 1):
        solve(mat[0])
    else:
        exp = ""
        i = 0
        while i < c:
            if (mat[1][i] == '='):
                a = ""
                b = ""
                while i < c and mat[1][i] == '=':
                    a += mat[0][i]
                    b += mat[2][i]
                    i += 1
                exp += "(" + a + ")/(" + b + ")";

            elif mat[1][i] == '/':
                i += 1
                a = ""
                while i < c and mat[0][i] == '_':
                    a += mat[1][i]
                    i += 1

                exp += "sqrt(" + a + ")";
            else:
                if (mat[1][i] != '=' and mat[1][i] != '\\'):
                    exp += mat[1][i]
                i += 1
        solve(exp)

