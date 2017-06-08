// http://codeforces.com/contest/814/problem/B

#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;
#define endl '\n'

int lack (vector<int> &v) {
  set<int> st(v.begin(), v.end());
  for (int i = 1; i <= v.size(); ++i) {
    if (st.count(i) == 0) return i;
  }

  return 0;
}

bool check (vector<int> &a, vector<int> &b, vector<int> &c) {
  if (!lack(c)) {
    int d1 = 0, d2 = 0;
    for (int i = 0; i < a.size(); ++i) {
      if (a[i] != c[i]) d1 ++;
      if (b[i] != c[i]) d2 ++;
    }

    return d1 == d2 && d1 == 1;
  }

  return false;
}

void out (vector<int> &v) {
  for (int i = 0; i < v.size(); ++i) cout << v[i] << " "; cout << endl;
}

int main() {
  int n;
  while (cin >> n) {
    vector<int> a(n), b(n), c, pos, r;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    for (int i = 0; i < n; ++i) if (a[i] != b[i]) pos.push_back(i);

    c = a;
    r.push_back(lack(a));
    r.push_back(lack(b));

    if (pos.size() == 1) {
      c[pos[0]] = r[0];
      if (check(a, b, c)) {
        out(c);
        continue;
      }

      c[pos[0]] = r[1];
      if (check(a, b, c)) {
        out(c);
        continue;
      }
    }
    else {
      bool ok = false;
      for (int i = 0; i < r.size() && !ok; ++i) {
        for (int j = 0; j < r.size() && !ok; ++j) {
          c[pos[0]] = r[i];
          c[pos[1]] = r[j];
          if (check (a, b, c)) {
            out(c);
            ok = true;
            break;
          }
        }
      }

      if (!ok) assert(false);
    }
  }

  return 0;
}