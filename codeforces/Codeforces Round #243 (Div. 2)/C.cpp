// http://codeforces.com/contest/426/problem/C

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
  int n,k;
  cin >> n >> k;

  vector<int> v(n), vv;
  for (int i = 0; i < n; ++i) cin >> v[i];

  int ans = -INT_MAX;
  for (int i = 0; i < n; ++i) {
    for (int j = 1; j + i <= n; ++j) {
      vector<int> vvv(v.begin() + i, v.begin() + i + j);
      vv = v;
      vv.erase(vv.begin() + i, vv.begin() + i + j);

      sort(all(vv));
      sort(all(vvv));

      int tmp = 0;
      int ind = vv.size() - 1;
      int x = 0;
      while ( vv[ind] > vvv[x] && x < k && x < vvv.size() && ind >= 0) {
        tmp += vv[ind];
        ind --;
        x ++;
      }

      while (x < vvv.size()) tmp += vvv[x ++];
      ans = max(ans, tmp);
    }
  }

  cout << ans;
  return 0;
}