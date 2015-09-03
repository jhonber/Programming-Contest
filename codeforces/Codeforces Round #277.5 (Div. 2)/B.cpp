// http://codeforces.com/contest/489/problem/B

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
  int n,m;
  cin >> n;

  vector<int> v(n);
  for (int i = 0; i < n; ++i)
    cin >> v[i];

  cin >> m;

  vector<int> vv(m);
  for (int i = 0; i < m; ++i)
    cin >> vv[i];


  sort(all(v));
  sort(all(vv));

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (vv[j] && v[i] && abs(v[i] - vv[j]) <= 1) {
        vv[j] = v[i] = 0;
        ans ++;
      }
    }
  }

  cout << ans;

  return 0;
}