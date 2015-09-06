// http://codeforces.com/contest/195/problem/B

#include<bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define foreach(it, x) for (__typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define all(x) x.begin(),x.end()
#define D(x) cout << #x " = " << (x) << endl;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

int dx[8] = {-1,-1,-1,0,1,1, 1, 0};
int dy[8] = {-1, 0, 1,1,1,0,-1,-1};

int main() {
  int n, m;
  cin >> n >> m;

  vector< long long > v(m, 0);

  int mid = (m + 1) / 2;
  int f = true;
  int cnt = m - 1;
  mid --;

  for (int i = 0; i < m; ++i) {
    v[i] = cnt;
    if (f) cnt -= 2;
    else cnt += 2;
    if (i == mid) {
      f = false;
      v[i] = 1;
      if (m % 2 == 0) cnt = 2;
      else cnt = 3;
    }
  }

  vector<int> ans(n + 100, 0);
  for (int i = 0; i < m; ++i) if (v[i] <= n) ans[v[i]] = i + 1;

  while (true) {
    for (int i = 0; i < m; ++i) {
      v[i] += m;
      if (v[i] <= n) ans[v[i]] = i + 1;
    }
    if (v[m - 1] > n) break;
  }

  for (int i = 1; i <= n; ++i) cout << ans[i] << endl;

  return 0;
}