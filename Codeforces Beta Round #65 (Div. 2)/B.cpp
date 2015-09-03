// http://codeforces.com/contest/71/problem/B

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
  int n,k,t;

  cin >> n >> k >> t;

  int a = n*k*t;
  int tot = 0;
  for ( ;tot <= n*k; ){
    if (tot*100 <= n*k*t &&  n*k*t < (tot+1)*100 )
      break;
    tot ++;
  }

  while (n--){
    if (tot-k >=0 ){
      tot -= k;
      cout << k << " ";
    }
    else {
      cout << tot << " ";
      tot -= tot;
    }
  }

  return 0;
}
