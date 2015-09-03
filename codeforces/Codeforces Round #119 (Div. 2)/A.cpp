// http://codeforces.com/contest/189/problem/A

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

const int INF = 1e7;

int v[3];
int ans = -INF;
int dp[4050];

int cut(int n, int c){
  if( dp[n] )
    return dp[n];

  if( n==0 )
    return c;

  for(int i=0; i<3; ++i)
    if(n-v[i]>=0)
      ans = max(ans, cut(n-v[i],c+1));

  return dp[n] = ans;
}

int main(){__
  int n, a, b, c;
  cin >> n >> v[0] >> v[1] >> v[2];

  sort(v,v+3);
  memset(dp, 0, sizeof dp);

  cout << cut(n, 0) << endl;

  return 0;
}