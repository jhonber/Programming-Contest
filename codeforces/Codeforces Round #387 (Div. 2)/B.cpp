// http://codeforces.com/contest/747/problem/B

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  string s;
  cin >> n >> s;

  if (n % 4 != 0) {
    cout << "===" << endl;
    return 0;
  }

  char v[] = {'A', 'C', 'G','T'};
  int tot[] = {0, 0, 0, 0};
  for (int i = 0; i < n; ++i) {
    if (s[i] == v[0]) tot[0] ++;
    if (s[i] == v[1]) tot[1] ++;
    if (s[i] == v[2]) tot[2] ++;
    if (s[i] == v[3]) tot[3] ++;
  }

  int len = n / 4;
  for (int i = 0; i < 4; ++i) {
    int t = len - tot[i];
    for (int j = 0; j < n && t; ++j) {
      if (s[j] == '?' && t) {
        s[j] = v[i];
        t --;
      }
    }
  }

  memset(tot, 0, sizeof tot);
  for (int i = 0; i < n; ++i) {
    if (s[i] == v[0]) tot[0] ++;
    if (s[i] == v[1]) tot[1] ++;
    if (s[i] == v[2]) tot[2] ++;
    if (s[i] == v[3]) tot[3] ++;
  }

  bool ok = true;
  for (int i = 0; i < 4; ++i) {
    if (tot[i] != len) ok = false;
  }

  cout << (ok ? s : "===") << endl;
  return 0;
}