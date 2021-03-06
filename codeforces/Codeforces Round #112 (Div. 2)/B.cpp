// http://codeforces.com/contest/165/problem/B

#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define D(x) cout << #x " = " << (x) << endl;

long long mpow(int a, int b) {
  long long p = 1;
  while (b --> 0) p *= a;
  return p;
}

long long sum (int v, int k) {
  long long ans = v;
  int pot = 1;
  while (true) {
    long long x = v / mpow(k, pot);
    if (x <= 0) break;
    ans += x;
    pot ++;
  }
  return ans;
}


int main () {
  int n, k;
  cin >> n >> k;

  int a = 1;
  int b = 1e9;
  int c;
  while (true) {
    c = (a + b) / 2;
    long long s = sum(c, k);
    if (s > n) {
      b = c;
    }
    else {
      if (sum(c + 1, k) >= n) {
        c ++;
        break;
      }
      a = c;
    }


  }
  if (sum(c - 1, k) >= n) cout << c - 1;
  else cout << c;

  return 0;
}