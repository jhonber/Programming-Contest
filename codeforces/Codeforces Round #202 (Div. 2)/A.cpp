// http://codeforces.com/contest/349/problem/A

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

  int n;
  cin >> n;

  int c1 = 0, c2 = 0, c3 = 0, t;
  for (int i=0; i<n; ++i) {
    cin >> t;
    if (t==25) {
      c1 ++;
    }
    else if (t==50) {
      c2 ++;
      c1 --;
      if (c1 < 0) {
        cout << "NO";
        return 0;
      }
    }
    else {
      c3 ++;
      c2 --;

      int tmp = 50;
      if (c2 < 0) {
       c2 ++;
       tmp = 0;
      }

      for (; tmp < 75 && c1 >=0;) {
        c1 --;
        tmp += 25;
      }

      if (c1 < 0 || c2 < 0) {
        cout << "NO";
        return 0;
      }
    }
  }

  cout << "YES";

  return 0;
}