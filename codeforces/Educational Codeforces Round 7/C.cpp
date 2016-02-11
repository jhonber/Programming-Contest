// http://codeforces.com/contest/622/problem/C

#include <bits/stdc++.h>
using namespace std ;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() { IO
  int n, m;
  cin >> n >> m;

  int ind = 0;
  vector<int> pos;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
    if (i == 0) {
      pos.push_back(i);
    }
    else {
      if (v[i] == v[i - 1]) continue;
      else pos.push_back(i);
    }
  }

  vector<int> next(n, -1);
  for (int i = 0; i < n - 1; ++i) {
    int ind = upper_bound(pos.begin(), pos.end(), i) - pos.begin();
    if (ind == pos.size()) next[i] = -1;
    else next[i] = pos[ind];
  }

  for (int i = 0; i < m; ++i) {
    int l, r, x;
    cin >> l >> r >> x; l --; r --;
    int found = false;

    if (v[l] != x) {
      cout << l + 1<< endl;
      found = true;
    }
    else {
      int pos = next[l];
      if (pos != -1 && pos <= r) {
        cout << pos + 1 << endl;
        found = true;
      }
    }

    if (!found) cout << -1 << endl;
  }

  return 0;
}