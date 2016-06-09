// http://codeforces.com/contest/677/problem/C

#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

const long long mod = 1e9 + 7;

long long f (char c) {
  if (c >= '0' && c <= '9') {
    return c - '0';
  }

  if (c >= 'A' && c <= 'Z') {
    return (c - 'A') + 10;
  }

  if (c >= 'a' && c <= 'z') {
    return (c - 'a') + 36;
  }

  if (c == '-') return 62;

  return 63;
}

int main() { IO
  string s;
  cin >> s;

  vector<long long> pre(66, 0);
  for (int i = 0; i < 64; ++i) {
    for (int j = 0; j < 64; ++j) {
      for (int k = 0; k < 64; ++k) {
        if ((j & k) == i)
          pre[i] ++;
      }
    }
  }

  long long ans = 1;
  for (int i = 0; i < s.size(); ++i) {
    long long x = f(s[i]);
    ans *= pre[x];
    ans %= mod;
  }

  cout << ans << endl;
  return 0;
}