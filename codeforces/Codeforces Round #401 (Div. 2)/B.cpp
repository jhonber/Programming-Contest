// http://codeforces.com/contest/777/problem/B

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  cin >> n;

  string a, b;
  cin >> a >> b;

  vector<int> aa;
  for (int i = 0; i < a.size(); ++i) {
    int d = a[i] - '0';
    aa.push_back(d);
  }

  map<int, int> m, tmp;
  for (int i = 0; i < b.size(); ++i) {
    int d = b[i] - '0';
    m[d] ++;
  }

  tmp = m;
  int ans1 = 0;
  for (int i = 0; i < n; ++i) {
    int x = aa[i];
    int d;
    auto lw = m.lower_bound(x + 1);
    if (lw != m.end()) {
      d = lw->first;
      m[d] --;
      if (m[d] == 0) m.erase(d);
    }
    else {
      d = m.begin()->first;
      m[d] --;
      if (m[d] == 0) m.erase(d);
    }

    if (aa[i] < d) ans1 ++;
  }

  m = tmp;
  int ans2 = 0;
  for (int i = 0; i < n; ++i) {
    int x = aa[i];
    int d;
    auto lw = m.lower_bound(x);
    if (lw != m.end()) {
      d = lw->first;
      m[d] --;
      if (m[d] == 0) m.erase(d);
    }
    else {
      d = m.begin()->first;
      m[d] --;
      if (m[d] == 0) m.erase(d);
    }

    if (aa[i] > d) ans2 ++;
  }

  cout << ans2 << endl << ans1 << endl;


  return 0;
}