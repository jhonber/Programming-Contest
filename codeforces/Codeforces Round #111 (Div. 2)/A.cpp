// http://codeforces.com/contest/160/problem/A

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
  int n;
  cin >> n;

  int tot = 0;
  int v[n];
  for (int i=0; i<n; ++i) {
    cin >> v[i];
    tot += v[i];
  }

  sort(v,v+n);

  int ans = 0;
  int res = 0;
  int i = n-1;
  while ( i >= 0 && tot >= res ){
    res +=  v[i];
    tot -= v[i];
    i-- ;
    ans ++;
  }

  cout << ans;

  return 0;
}