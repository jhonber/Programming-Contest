// http://codeforces.com/contest/462/problem/B

#include<bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define foreach(it, x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define all(x) x.begin(),x.end()
#define D(x) cout << #x " = " << (x) << endl;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

int dx[8] = {-1,-1,-1,0,1,1, 1, 0};
int dy[8] = {-1, 0, 1,1,1,0,-1,-1};

int main(){ __
  int n,k;
  cin >> n >> k;

  map<char,int> mapa;

  for (int i=0; i<n; ++i) {
    char c;
    cin >> c;
    mapa[c] ++;
  }

  vector< pair<int,char> > v;
  foreach(x,mapa) {
    v.push_back(make_pair(x->second,x->first));
  }

  sort(all(v));

  long long ans = 0;
  for (int i=v.size()-1; i>=0; --i) {
    if (v[i].first <= k) {
      k -= v[i].first;
      ans += (v[i].first + 0LL) * (v[i].first + 0LL) ;
      continue;
    }
    if (v[i].first > k) {
      ans += (k + 0LL) * (k + 0LL);
      break;
    }
  }

  cout << ans;
  return 0;
}