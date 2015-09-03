// http://codeforces.com/contest/203/problem/A

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

int main(){__
  int x,t,a,b,da,db;
  cin >> x >> t >> a >> b >> da >> db;

  if (!x) {
    cout << "YES";
    return 0;
  }

  int s1=a, s2;
  for (int i=0; i<t; ++i) {
    s2 = b;
    for (int j=0; j<t; ++j) {
      if(s1 + s2 == x || s1 == x || s2 == x) {
        cout << "YES";
        return 0;
      }
      s2 -= db;
    }
    s1 -= da;
  }

  cout << "NO";
  return 0;
}