// http://codeforces.com/contest/479/problem/B

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
  int n,k;
  cin >> n >> k;

  int tot = 0,k2 = k;
  vector< pair<int,int> > v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i].first;
    v[i].second = i + 1;
    tot += v[i].first;
  }

  int med = ((double)tot / (double)n) + 0.5;
  sort(all(v));
  vector< pair<int,int> > ans;

  int i = n - 1, j = 0;
  while ( v[i].first > med && k > 0 ) {
    v[j].first ++;
    v[i].first --;
    k --;
    ans.push_back( make_pair(v[i].second, v[j].second) );
    sort(all(v));
  }

  int s = v[i].first - v[j].first;
  cout << s << " " << ans.size() << endl;

  for (int i = 0; i < ans.size(); ++i)
    cout << ans[i].first << " " << ans[i].second << endl;

  return 0;
}