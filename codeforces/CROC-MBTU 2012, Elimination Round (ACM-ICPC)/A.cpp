// http://codeforces.com/contest/245/problem/A

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

  int n;
  cin >> n;

  int tota = 0, susa = 0;
  int totb = 0, susb = 0;
  for(int i=0; i<n; ++i){
    int a, b, c;
    cin >> a >> b >> c;

    if(a == 1){
      tota += b+c;
      susa += b;
    }
    else {
      totb += b+c;
      susb += b;
    }
  }

  if(tota){
    if( susa >= tota/2 )
      cout << "LIVE" << endl;
    else cout << "DEAD" << endl;
  }


  if(totb){
    if( susb >= totb/2 )
      cout << "LIVE" << endl;
    else cout << "DEAD" << endl;
  }

  return 0;
}