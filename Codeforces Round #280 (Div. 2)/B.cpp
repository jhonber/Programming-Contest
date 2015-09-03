// http://codeforces.com/contest/492/problem/B

#include<bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define foreach(it, x) for (__typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define all(x) x.begin(),x.end()
#define d(x) cout << #x " = " << (x) << endl;

template <class t> string tostr(const t &x)
{ stringstream s; s << x; return s.str(); }

template <class t> int toint(const t &x)
{ stringstream s; s << x; int r; s >> r; return r; }

int dx[8] = {-1,-1,-1,0,1,1, 1, 0};
int dy[8] = {-1, 0, 1,1,1,0,-1,-1};

int main(){ __
  int n,l;
  cin >> n >> l;

  vector<double> v(n);
  for (int i = 0; i < n; ++i)
    cin >> v[i];

  sort(all(v));

  double ans = -INT_MAX;

  for (int i = 1; i < n; ++i) {
    ans = max(ans,(v[i] - v[i - 1]) / 2.0);
  }

  ans = max(ans,max(v[0], l - v[n - 1]));
  cout.precision(9);
  cout << ans;

  return 0;
}