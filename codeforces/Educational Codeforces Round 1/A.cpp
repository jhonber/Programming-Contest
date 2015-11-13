// http://codeforces.com/contest/598/problem/A

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;
#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);

long long sum(long long n) {
  return (n * (n + 1)) / 2;
}

int main () {
  int t;
  cin >> t;
  while (t -- > 0) {
    long long n;
    cin >> n;


    long long s  = sum(n);

    long long pot2 = 1;
    int i = 0;
    while (pot2 <= n) pot2 *= 2;
    pot2 --;
    cout << (s - pot2) - pot2 << endl;
  }
  return 0;
}