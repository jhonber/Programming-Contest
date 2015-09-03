// http://codeforces.com/contest/402/problem/C

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
  int t,n,p;
  cin >> t;

  for(int i=0; i<t; ++i){
    cin >> n >> p;

    int c = 1;
    int paila = false;
    for(int j=1; j<=n; ++j){
      for(int k=j+1; k<=n; ++k){
        cout << j << " " << k << endl;
        if(c == (2*n)+p){
          paila = true;
          break;
        }
        c++;
      }
      if(paila)
        break;
    }
  }
  return 0;
}