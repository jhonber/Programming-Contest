// http://codeforces.com/contest/401/problem/B

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
  int x,k;

  cin >> x >> k;
  vector<int> v(x+1,0);
  v[x] = true;

  for(int i=0; i<k; ++i){
    int t,a,b;
    cin >> t;
    if(t==1){
      cin >> a >> b;
      v[a] = v[b] = true;
    }
    else {
      cin >> a;
      v[a] = true;
    }
  }

  int mmax = 0, mmin = 0;
  for(int i=1; i<x; ++i){
    if(!v[i]) mmax ++;
  }

  for(int i=1; i<x; ){
    if(!v[i] && !v[i+1]){
      mmin ++;
      i+=2;
    }
    else if(!v[i]){
      mmin ++;
      i++;
    }
    else i++;
  }

  cout << mmin << " " << mmax;

  return 0;
}
