// http://codeforces.com/contest/447/problem/C

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

  int r[n];
  int l[n];

  r[0] = l[n - 1] = 1;

  for (int i = 1; i < n; ++i) {
    if (v[i - 1] < v[i]) r[i] = r[i - 1] + 1;
    else r[i] = 1;
  }

  for (int i = n - 2; i >= 0; --i) {
    if (v[i] < v[i + 1]) l[i] = l[i + 1] + 1;
    else l[i] = 1;
  }

  int ans = 1;
  if (n > 1) {
    ans = max(ans, r[n - 2] + 1);
    ans = max(ans, l[1] + 1);
    for (int i = 1; i < n - 1; ++i) {
      if (v[i - 1] + 1 < v[i + 1]) ans = max(ans, r[i - 1] + 1 + l[i + 1]);
      ans = max(ans, r[i - 1] + 1);
      ans = max(ans, l[i + 1] + 1);
    }
  }

  cout << ans;
  return 0;
}