// http://codeforces.com/contest/812/problem/B

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int n, m, best, first;

int count_steps (string &s, bool dir) {
  int l = 0, r = 0;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == '1') r = i;
    if (!l && s[i] == '1') l = i;
  }

  if (!l) return 0;
  if (!dir) return r;
  return m - l - 1;
}

void solve(int lev, int dir, int steps, vector<string> &v) {
  if (lev + 1 >= first) {
    int d = count_steps(v[lev], dir);
    best = min(best, steps + d);
    return;
  }

  if (!dir) {
    int d = count_steps(v[lev], 0);
    solve (lev + 1, 0, steps + d + d, v);
    solve (lev + 1, 1, steps + m - 1, v);
  }
  else {
    int d = count_steps(v[lev], 1);
    solve (lev + 1, 0, steps + m - 1, v);
    solve (lev + 1, 1, steps + d + d, v);
  }
}

int main() {
  while (cin >> n >> m) {
    vector<string> rows(n);

    best = INT_MAX;
    m += 2;
    bool f = true;
    for (int i = 0; i < n; ++i) {
      cin >> rows[i];
      if (f && rows[i].find('1') != string::npos) {
        f = false;
        first = n - i;
      }
    }

    reverse(rows.begin(), rows.end());

    int d = count_steps (rows[0], 0);
    int ans = d;

    if (n > 1 && first > 1) {
      solve(1, 0, 2 * ans, rows);
      solve(1, 1, m - 1, rows);
    }
    else {
      int d = count_steps (rows[0], 0);
      cout << d << endl;
      continue;
    }

    cout << best + first - 1 << endl;
  }

  return 0;
}