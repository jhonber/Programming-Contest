// http://codeforces.com/contest/441/problem/A

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

int main(){__
  int n,v;
  cin >> n >> v;

  int ans = 0;
  vector<int> vv;
  for(int i=0; i<n; ++i){
    int t,k;
    cin >> t;
    int mmin = INT_MAX;
    for(int j=0; j<t; ++j){
      cin >> k;
      mmin = min(mmin,k);
    }
    if(mmin < v){
      vv.push_back(i+1);
      ans++;
    }
  }

  cout << ans << endl;
  for(int i=0; i<ans; ++i)
    cout << vv[i] << " ";

  return 0;
}
