// http://codeforces.com/contest/499/problem/A

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
  int n,x;
  cin >> n >> x;

  vector< pair<int,int> > v(n);
  for (int i = 0; i < n; ++i)
    cin >> v[i].first >> v[i].second;

  sort(all(v));

  int last = min(1,v[0].first);
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int tot = v[i].first - last;
    int tmp = tot - ((tot / x) * x);
    ans += tmp;
    ans += v[i].second - v[i].first + 1;
    last = v[i].second + 1;
  }

  cout << ans;

  return 0;
}