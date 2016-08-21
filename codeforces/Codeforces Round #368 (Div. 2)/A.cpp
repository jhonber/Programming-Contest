// http://codeforces.com/contest/707/problem/A

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n, m;
  cin >> n >> m;

  int good = 0;
  int o = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      char c;
      cin >> c;
      if (c == 'W' || c == 'G' || c == 'B') good ++;
      else o ++;
    }
  }

  if (!o) cout << "#Black&White" << endl;
  else cout << "#Color" << endl;
  return 0;
}