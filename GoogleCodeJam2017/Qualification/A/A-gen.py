from random import randint as rd

tc = 10000
n = 15

s = ['+', '-']

print tc

for i in range(0, tc):
    l = rd(10, n)
    k = rd(2, l)
    out = ""
    for j in range(0, l):
        out = out + str(s[rd(0, 1)]);

    print out, k
