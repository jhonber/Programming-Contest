# http://codeforces.com/contest/16/problem/C

from fractions import gcd
def main():
    a,b,x,y = map(int,raw_input().split())
    k = gcd(x,y)
    x = x / k
    y = y / k
    m = min(a / x , b / y);
    print m * x,m * y

main()
