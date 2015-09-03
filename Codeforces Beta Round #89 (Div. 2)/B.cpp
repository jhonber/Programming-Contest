// http://codeforces.com/contest/118/problem/B

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

  for(int i=n*2, xx = 0; i>=0; i-=2, ++xx){
    for(int x=0; x<i; ++x) cout << " ";
    for(int j=0; j<=xx; ++j){
      cout << j;
      if(j<xx) cout << " ";
    }

    for(int j=xx-1; j>=0; --j)
      cout << " "<< j;

    cout << endl;
  }

  for(int i=2, xx = n-1; i<=n*2; i+=2, --xx){
    for(int x=0; x<i; ++x) cout << " ";
    for(int j=0; j<=xx; ++j) {
      cout << j;
      if(j<xx) cout << " ";
    }
    for(int j=xx-1; j>=0; --j)
      cout << " "<< j;

    cout << endl;
  }

  return 0;
}