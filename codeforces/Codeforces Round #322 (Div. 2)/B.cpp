// http://codeforces.com/contest/581/problem/B

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
  int n;
  cin >> n;

  vector<int> v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];

  int pre[n];
  memset(pre, 0, sizeof pre);

  int mmax = -INT_MAX;
  for (int i = n - 1; i >= 0; --i) {
    mmax = max(mmax, v[i]);
    pre[i] = mmax;
  }

  for (int i = 0; i + 1 < n; ++i) {
    int ans = 0;
    if (pre[i + 1] >= v[i] ) ans = pre[i + 1] - v[i] + 1;
    cout << ans << " ";
  }
  cout << 0 << endl;

  return 0;
}
