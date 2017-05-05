// http://codeforces.com/contest/805/problem/D

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

const long long mod = 1e9 + 7;

int main() {
  string s;
  while (cin >> s) {

    long long ans = 0;
    long long as = 1;

    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == 'a') {
        as *= 2;
        as %= mod;
      }
      else {
        ans += (as - 1 + mod) % mod;
        ans %= mod;
      }
    }

    cout << ans << endl;
  }

  return 0;
}