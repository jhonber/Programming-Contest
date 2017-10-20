// http://codeforces.com/contest/876/problem/B

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main () {
  int n, k, m;
  while (cin >> n >> k >> m) {
    map<int, vector<int>> cnt;
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      cnt[x % m].push_back(x);
    }

    bool ok = false;
    for (auto i: cnt) {
      vector<int> v = i.second;
      if (v.size() >= k) {
        cout << "Yes" << endl;
        for (int j = 0; j < k; ++j) cout << v[j] << " "; cout << endl;
        ok = true;
        break;
      }
    }

    if (!ok) cout << "No" << endl;
  }

  return 0;
}