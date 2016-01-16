# http://codeforces.com/contest/614/problem/A

input = map(int, raw_input().split())
l = input[0]
r = input[1]
k = input[2]

pot = 1
found = False

while (pot <= r):
    if (pot >= l and pot <= r):
        print pot,
        found = True
    pot = pot * k

if (not found):
    print -1