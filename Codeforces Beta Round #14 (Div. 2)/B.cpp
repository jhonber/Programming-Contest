// http://codeforces.com/contest/14/problem/B

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
  int n,x,a,b;
  cin >> n >> x;

  int f = false;
  vector<int> v(1111,0);
  for (int i = 0; i < n; ++i) {
    cin >> a >> b;
    int mmin = min(a,b);
    int mmax = max(a,b);
    for (int j = mmin; j <= mmax; ++j) {
      v[j] ++;
      if (v[j] == n) f = true;
    }
  }

  if (!f) {
    cout << -1;
    return 0;
  }

  int ans = INT_MAX;
  for (int i = 0; i < 1110; ++i)
    if (v[i] == n)
      ans = min(ans, abs(i - x));

  cout << ans;

  return 0;
}