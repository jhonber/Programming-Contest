// http://codeforces.com/contest/583/problem/B

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

  int dir = true;
  int acum = 0;
  int tot = n;
  int ans = 0;
  int f = 0;

  while (tot > 0) {
    if (f % 2 == 0) {
      if (!dir) ans ++;
      for (int i = 0; i < n; ++i) if (v[i] <= acum) {
        acum ++;
        tot --;
        v[i] = INT_MAX;
      }
      dir = true;
    }
    else {
      if (dir) ans ++;
      for (int i = n - 1; i >= 0; --i) if (v[i] <= acum) {
        acum ++;
        tot --;
        v[i] = INT_MAX;
      }
      dir = false;
    }
    f ++;
  }

  cout << ans;
  return 0;
}