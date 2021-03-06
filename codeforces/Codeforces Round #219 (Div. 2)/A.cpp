// http://codeforces.com/contest/373/problem/A

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
  int k;
  cin >> k;

  int v[9] = {0,0,0,0,0,0,0,0,0};
  for(int i=0; i<4; ++i){
    for(int j=0; j<4; ++j){
      char t;
      cin >> t;
      if(t=='.') continue;
      t = toInt(t);
      v[t-1] ++;
    }
  }

  for(int i=0; i<9; ++i){
    if(v[i] > k*2){
      cout << "NO";
      return 0;
    }
  }

  cout << "YES";
  return 0;
}