// http://codeforces.com/contest/279/problem/C

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() { IO
  int n, m;
  cin >> n >> m;

  vector<int> v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];

  vector<int> cnt(n);

  map<pair<int, int>, bool> keys;
  vector<int> left, right;

  int ind = 0;
  while (ind + 1 < n) {
    if (v[ind] >= v[ind + 1]) {
      while (ind + 1 < n && v[ind] >= v[ind + 1]) {
        ind ++;
      }
    }
    else {
      while (ind + 1 < n && v[ind] <= v[ind + 1]) {
        ind ++;
      }

      while (ind + 1 < n && v[ind] >= v[ind + 1]) {
        ind ++;
      }
    }

    if (ind + 1 < n && v[ind] < v[ind + 1]) {
      cnt[ind] = cnt[ind + 1] = true;
      keys[{ind, ind + 1}] = true;
      left.push_back(ind);
    }
  }

  ind = n - 1;
  while (ind - 1 >= 0) {
    if (v[ind] >= v[ind - 1]) {
      while (ind - 1 >= 0 && v[ind] >= v[ind - 1]) {
        ind --;
      }
    }
    else {
      while (ind - 1 >= 0 && v[ind] <= v[ind - 1]) {
        ind --;
      }

      while (ind + 1 < n && v[ind] >= v[ind - 1]) {
        ind --;
      }
    }

    if (ind - 1 >= 0 && v[ind] < v[ind - 1]) {
      cnt[ind] ++;
      cnt[ind - 1] ++;
      keys[{ind - 1, ind}] = true;
      right.push_back(ind - 1);
    }
  }

  sort(right.begin(), right.end());

  vector<int> sum(n + 1);
  sum[0] = 0;
  for (int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + cnt[i - 1];

  int l, r;
  for (int i = 0; i < m; ++i) {
    cin >> l >> r;

    int tot = sum[r] - sum[l - 1];
    if (keys[{l - 2, l - 1}]) tot --;
    if (keys[{r - 1, r}]) tot --;

    if (tot > 4) cout << "No" << endl;
    else if (tot == 4) {
      auto ll = *lower_bound(left.begin(), left.end(), l - 1);
      auto rr = *lower_bound(right.begin(), right.end(), l - 1);

      if (ll > rr) cout << "No" << endl;
      else cout << "Yes" << endl;
    }
    else cout << "Yes" << endl;
  }

  return 0;
}