// http://codeforces.com/contest/701/problem/A

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  cin >> n;

  vector<int> v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];

  for (int i = 1; i <= 10100; ++i) {
    vector<int> ans;
    vector<int> mark(n, 0);
    int cur = i;

    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < n; ++k) {
        if (j == k) continue;
        if (!mark[j] && !mark[k] && v[j] + v[k] == cur) {
          mark[j] = mark[k] = true;
          ans.push_back(j + 1);
          ans.push_back(k + 1);
        }
      }
    }

    if (ans.size() == n) {
      for (int j = 0; j < ans.size(); j += 2) cout << ans[j] << " " << ans[j + 1] << endl;
      return 0;
    }
  }

  return 0;
}