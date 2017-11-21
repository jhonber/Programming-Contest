// http://codeforces.com/contest/888/problem/A

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  while (cin >> n) {
    int ans = 0;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
      cin >> v[i];
    }

    for (int i = 1; i + 1 < n; ++i) {
      if (v[i] > v[i - 1] && v[i] > v[i + 1] || v[i] < v[i - 1] && v[i] < v[i + 1]) ans ++;
    }

    cout << ans << endl;
  }

  return 0;
}