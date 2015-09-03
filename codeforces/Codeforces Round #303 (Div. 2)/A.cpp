// http://codeforces.com/contest/545/problem/A

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

int main() { __
  int n;
  cin >> n;

  int mat[n][n];
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> mat[i][j];
    }
  }

  vector<int> ans(n, true);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (mat[i][j] == 1) ans[i] = false;
      else if (mat[i][j] == 2) ans[j] = false;
      else if (mat[i][j] == 3) ans[i] = ans[j] = false;
    }
  }

  int cnt = 0;
  for (int i = 0; i < n; ++i) if (ans[i]) cnt ++;

  cout << cnt << endl;
  for (int i = 0; i < n; ++i) if (ans[i]) cout << i + 1 << " ";


  return 0;
}