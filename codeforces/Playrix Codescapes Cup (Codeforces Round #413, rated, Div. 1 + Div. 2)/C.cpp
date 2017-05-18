// http://codeforces.com/contest/799/problem/C

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

const int N = 3 * 1e5;

int query (int x, int y, int id, int l, int r, vector<int> &ans) {
  if (l >= y || x >= r) return -1;
  if (x <= l && r <= y) return ans[id];

  int mid = (l + r) / 2;
  int a = query (x, y, 2 * id, l, mid, ans);
  int b = query (x, y, 2 * id + 1, mid, r, ans);

  return max(a, b);
}

void init (int id, int l, int r, vector<int> &v, vector<int> &ans) {
  if (v.size() == 0) return;

  if (r - l < 2) {
    ans[id] = v[l];
    return;
  }

  int mid = (r + l) / 2;
  init (2 * id, l, mid, v, ans);
  init (2 * id + 1, mid, r, v, ans);

  ans[id] = max(ans[2 * id], ans[2 * id + 1]);
}

int get_ind_upper (int x, int to, vector<pair<int, int>> &v) {
  if (v.size() == 0) return -1;

  pair<int, int> tmp = {x, 0};
  auto up = upper_bound(v.begin(), v.begin() + to, tmp);
  if (up == v.begin()) {
    if (up->first > x) return -1;
    return 1;
  }
  return up - v.begin();
}

int main() {
  int n, c, d;

  while (cin >> n >> c >> d) {
    vector<pair<int, int>> a, b;
    for (int i = 0; i < n; ++i) {
      int x, y; char c;
      cin >> x >> y >> c;
      if (c == 'C') a.push_back({y, x});
      else b.push_back({y, x});
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector<int> A, B;
    for (int i = 0; i < a.size(); ++i) A.push_back(a[i].second);
    for (int i = 0; i < b.size(); ++i) B.push_back(b[i].second);

    vector<int> ansA(N, 0), ansB(N, 0);

    init (1, 0, A.size(), A, ansA);
    init (1, 0, B.size(), B, ansB);

    int ans = 0;
    for (int i = 0; i < a.size(); ++i) {
      if (a[i].first <= c) {
        int r = get_ind_upper(d, b.size(), b);
        if (r != -1) {
          ans = max(ans, a[i].second + query(0, r, 1, 0, B.size(), ansB));
        }
      }
    }

    for (int i = a.size() - 1; i > 0; --i) {
      if (a[i].first <= c) {
        int k = c - a[i].first;
        int r = get_ind_upper(k, i, a);
        if (r != -1) {
          int calc = query(0, r, 1, 0, A.size(), ansA);
          ans = max(ans, a[i].second + calc);
        }
      }
    }

    for (int i = b.size() - 1; i > 0; --i) {
      if (b[i].first <= d) {
        int k = d - b[i].first;
        int r = get_ind_upper(k, i, b);
        if (r != -1) {
          int calc = query(0, r, 1, 0, B.size(), ansB);
          ans = max(ans, b[i].second + calc);
        }
      }
    }

    cout << ans << endl;
  }

  return 0;
}