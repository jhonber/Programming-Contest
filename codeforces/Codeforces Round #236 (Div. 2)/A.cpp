// http://codeforces.com/contest/402/problem/A

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
  int k, a, b, v;
  cin >> k >> a >> b >> v;

  int ans = 0;
  while( a>0 ){
    if(b-(k-1) >= 0){
      b -= k-1;
      a -= (k*v);
    }
    else {
      if(b > 0){
        a -= (b+1)*v;
        ans ++;
      }
      break;
    }
    ans ++;
  }

  if(a>0)
    cout << ans + ceil((double)a/(double)v);
  else
    cout << ans;

  return 0;
}