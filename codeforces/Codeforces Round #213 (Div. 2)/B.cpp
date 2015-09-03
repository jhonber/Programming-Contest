// http://codeforces.com/contest/365/problem/B

#include<bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

#define foreach(it, x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define all(x) x.begin(),x.end()
#define D(x) cout << #x " = " << (x) << endl;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

int dx[8] = {-1,-1,-1,0,1,1, 1, 0};
int dy[8] = {-1, 0, 1,1,1,0,-1,-1};

int main(){
  int n;
  cin >> n;

  if(n==1){
    cout << 1;
    return 0;
  }

  vector<int> v(n);
  for(int i=0; i<n; ++i)
    cin >> v[i];

  int ans = 0;
  int c = 2;
  for(int i=n-1; i>=2;--i){
    if( v[i-1]+v[i-2] == v[i] )
      ++c;
    else {
      ans = max(ans,c);
      c = 2;
    }
  }

  ans = max(c,ans);

  cout << ans;
  return 0;
}