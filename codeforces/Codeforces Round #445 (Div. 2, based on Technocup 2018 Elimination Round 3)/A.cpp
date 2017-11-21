// http://codeforces.com/contest/890/problem/A

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int tot = 0;
  vector<int> v(6);
  for (int i = 0; i < 6; ++i) {
    cin >> v[i];
    tot += v[i];
  }

  for (int i = 0; i < 6; ++i) {
    for (int j = 0; j < 6; ++j) {
      for (int k = 0; k < 6; ++k) {
        if (i == j || i == k || j == k) continue;
        int t = v[i] + v[j] + v[k];
        if (t == tot - t) {
          cout << "YES" << endl;
          return 0;
        }
      }
    }
  }

  cout << "NO" << endl;

  return 0;
}