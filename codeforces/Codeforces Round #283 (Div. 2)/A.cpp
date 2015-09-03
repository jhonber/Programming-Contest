// http://codeforces.com/contest/496/problem/A

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

int main(){ __
  int n;
  cin >> n;

  vector<int> v(n),vv;
  for (int i = 0; i < n; ++i) cin >> v[i];

  int ans = INT_MAX;
  int i = 1;
  while ( i < n - 1 ) {
    vv = v;
    vv.erase(vv.begin() + i);

    int tmp = -INT_MAX;
    for (int j = 0; j < vv.size() - 1; ++j)
      tmp = max(tmp, vv[j+1] - vv[j]);

    ans = min(tmp,ans);
    i ++;
  }

  cout << ans;

  return 0;
}