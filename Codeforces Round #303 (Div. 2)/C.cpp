// http://codeforces.com/contest/545/problem/C

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

int main() { __
  int n;
  cin >> n;

  vector<int> v(n);
  vector<int> vv(n);
  for (int i = 0; i < n; ++i) cin >> v[i] >> vv[i];

  int ans = min(2, n);
  for (int i = 1; i + 1 < n; ++i) {
    int l = v[i] - v[i - 1];
    int r = v[i + 1] - v[i];

    if (vv[i] < l) ans ++;
    else if (vv[i] < r) {
      v[i] += vv[i];
      ans ++;
    }
  }

  cout << ans;
  return 0;
}