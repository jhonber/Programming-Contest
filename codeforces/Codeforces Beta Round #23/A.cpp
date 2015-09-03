// http://codeforces.com/contest/23/problem/A

#include<bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define foreach(it, x) for (__typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define all(x) x.begin(),x.end()
#define D(x) cout << #x " = " << (x) << endl;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

int dx[8] = {-1,-1,-1,0,1,1, 1, 0};
int dy[8] = {-1, 0, 1,1,1,0,-1,-1};

int main() {
  string s;
  cin >> s;

  int n = s.size();

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 1; j + i < n; ++j) {
      string sub = s.substr(i,j);
      int f = 0;
      for (int x = 0; x < n; ++x) if (sub == s.substr(x,j)) f ++;

      if (f > 1) ans = max(ans, j);
    }
  }

  cout << ans;
  return 0;
}