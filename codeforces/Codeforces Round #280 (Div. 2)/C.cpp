// http://codeforces.com/contest/492/problem/C

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
  long long n,r,avg;
  cin >> n >> r >> avg;

  long long ssum = 0;
  long long a,b;
  vector< pair<long long,long long> > v;

  for (int i = 0; i < n; ++i) {
    cin >> a >> b;
    if (a != r) v.push_back(make_pair(b,a));
    ssum += a;
  }

  sort(all(v));

  long long ans = 0, tmp;
  for (int i = 0; i < v.size(); ++i) {
    if (ssum >= n * avg) break;
    pair<long long,long long> cur = v[i];
    tmp = min((n * avg) - ssum, r - cur.second);
    ans += tmp * cur.first;
    ssum += tmp;
  }

  cout << ans;
  return 0;
}