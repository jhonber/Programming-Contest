// http://codeforces.com/contest/580/problem/B

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
  long long n, d;
  cin >> n >> d;

  vector< pair<long long, long long> > v(n);
  for (int i = 0; i < n; ++i) cin >> v[i].first >> v[i].second;

  sort(all(v));

  long long psum[n + 1];
  memset(psum, 0, sizeof psum);

  for (int i = 1; i <= n; ++i) {
    psum[i] = psum[i - 1] + v[i - 1].second;
  }

  long long ans = 0;
  vector< pair<long long, long long> > :: iterator upp;
  for (int i = 0; i < n; ++i) {
    long long x = v[i].first + d;
    upp = upper_bound(all(v), make_pair(x, 0LL));
    if (upp != v.begin()) upp --;

    int ind = (upp - v.begin()) + 1;
    long long tmp = psum[ind] - psum[i];
    if (tmp > ans) {
      ans = tmp;
    }
  }

  cout << ans;
  return 0;
}