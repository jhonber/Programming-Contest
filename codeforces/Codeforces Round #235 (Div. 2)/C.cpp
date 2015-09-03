// http://codeforces.com/contest/401/problem/C

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

int main(){__
  int n, m;
  cin >> n >> m;

  string ans;
  if( m >= n ){
    int res = m-n;
    if( m >= n-1 && m <= (2*n)+2 ){
      m = m-res;
      while( n>0 || m>0 || res>0){
        if(m-- > 0)
          ans += "1";
        if(res-- > 0)
          ans += "1";
        if(n-- > 0)
          ans += "0";
      }
      cout << ans;
    }
    else cout << -1;
  }
  else {
    if( n >= m-1 && n <= m+1 ){
      while( n>0 || m>0 ){
        if(n-- > 0)
          ans += "0";
        if(m-- > 0)
          ans += "1";
      }
      cout << ans;
    }
    else cout << -1;
  }


  return 0;
}