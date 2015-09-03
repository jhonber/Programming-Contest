// http://codeforces.com/contest/552/problem/A

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
  int n;
  cin >> n;

  int mat[111][111];
  memset(mat, 0, sizeof mat);

  for (int i = 0; i < n; ++i) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;


    for (int j = y1; j <= y2; ++j) {
      for (int k = x1; k <= x2; ++k) {
        mat[j][k] ++;
      }
    }
  }

  int ans = 0;
  for (int j = 0; j < 111; ++j) {
    for (int k = 0; k < 111; ++k) {
      ans += mat[j][k];
    }
  }

  cout << ans;
}

