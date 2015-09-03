// http://codeforces.com/contest/479/problem/C

#include<bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define foreach(it, x) for (__typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define all(x) x.begin(),x.end()
#define D(x) cout << #x " = " << (x) << endl;

template <class t> string tostr(const t &x)
{ stringstream s; s << x; return s.str(); }

template <class t> int toint(const t &x)
{ stringstream s; s << x; int r; s >> r; return r; }

int dx[8] = {-1,-1,-1,0,1,1, 1, 0};
int dy[8] = {-1, 0, 1,1,1,0,-1,-1};

int main(){ __
  int n;
  cin >> n;

  vector< pair<int,int> > v(n);
  for (int i = 0; i < n; ++i)
    cin >> v[i].first >> v[i].second;

  sort(all(v));

  int ans = min(v[0].first, v[0].second);
  for (int i = 1; i < n; ++i) {
    if (v[i].second >= ans) ans = min(v[i].second, v[i].first);
    else ans = v[i].first;
  }

  cout << ans;
  return 0;
}