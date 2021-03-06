// http://codeforces.com/contest/155/problem/B

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

  vector< pair<int,int> > v(n);
  for (int i = 0; i < n; ++i) {
    int a,b;
    cin >> a >> b;
    v[i] = make_pair(b,a);
  }

  int ans = 0;
  sort(all(v));

  int cnt = 1;
  int i   = n - 1;
  while (cnt > 0 and i >= 0) {
    cnt --;
    cnt += v[i].first;
    ans += v[i].second;
    i --;
  }

  cout << ans;
  return 0;
}