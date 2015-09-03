// http://codeforces.com/contest/16/problem/B

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
  int n,m;
  cin >> n >> m;

  int a,b;
  vector< pair<int,int> > v(m);
  for (int i = 0; i < m; ++i) {
    cin >> a >> b;
    v[i] = make_pair(b,a);
  }

  sort(all(v));
  reverse(all(v));

  long long ans = 0;
  for (int i = 0; i < m && n > 0; ++i) {
    int b = v[i].first;
    int a = v[i].second;
    if (a >= n) {
      ans += (n + 0LL) * b;
      n = 0;
    }
    else {
      n -= a;
      ans += (a + 0LL) * b;
    }
  }

  cout << ans;
  return 0;
}