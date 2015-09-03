// http://codeforces.com/contest/399/problem/A

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
  int n,p,k;
  cin >> n >> p >> k;
  string ans;

  string m = "(" + toStr(p) + ")";
  string izq;
  string der;

  int f = false;
  for(int i = p-1,j=0; i>=1 && j<k; --i,++j ){
    izq = toStr(i) + " " + izq;
    if(i==1) f = true;
  }

  if(!f && p!=1) izq = "<< " + izq;

  f = false;
  for(int i = p+1, j=0; i<=n && j<k ; ++i,++j ){
    der = der + " " + toStr(i);
    if(i==n) f = true;
  }

  if(!f && p!=n) der = der + " >>";

  ans = izq + m + der;

  cout << ans;

  return 0;
}