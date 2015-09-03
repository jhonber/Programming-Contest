// http://codeforces.com/contest/483/problem/C

#include<bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define foreach(it, x) for(__typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define all(x) x.begin(),x.end()
#define D(x) cout << #x " = " << (x) << endl;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

int dx[8] = {-1,-1,-1,0,1,1, 1, 0};
int dy[8] = {-1, 0, 1,1,1,0,-1,-1};

int main(){ __
  int n,k;
  cin >> n >> k;

  int mmax = n;
  int mmin = 1;
  int cnt = 1;
  cout << " " << n;
  mmax --;

  for (int i = 1; i < n; ++i) {
    if (cnt < k) {
      if (i % 2 != 0)
        cout << " " << mmin ++;
      else
        cout << " " << mmax --;

      cnt ++;
    }
    else {
      for (int j = i; j < n; ++j) {
        if (i % 2 == 0) cout << " " << mmin ++;
        else cout << " " <<  mmax --;
      }
      return 0;
    }
  }

  return 0;
}