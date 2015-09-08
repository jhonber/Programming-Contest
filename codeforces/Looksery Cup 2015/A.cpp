// http://codeforces.com/contest/549/problem/A

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
  int n,m;
  cin >> n >> m;

  char mat[n + 10][m + 10];
  memset(mat, 'x', sizeof mat);

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> mat[i][j];
    }
  }


  string s = "acef";
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      vector<char> v;
      v.push_back(mat[i][j]);
      v.push_back(mat[i][j + 1]);
      v.push_back(mat[i + 1][j]);
      v.push_back(mat[i + 1][j + 1]);

      sort(all(v));
      int match = true;
      for (int x = 0; x < 4; ++x) if (v[x] != s[x]) match = false;
      if (match) ans ++;
    }
  }


  cout << ans;
  return 0;
}