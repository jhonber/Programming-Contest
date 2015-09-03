// http://codeforces.com/contest/548/problem/B

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

int n,m;
bool mat[555][555];

int countRow(int n) {
  int cnt = 0;
  int tmp = 0;
  for (int i = 0; i < m; ++i) {
    if (mat[n][i]) tmp ++;
    else tmp = 0;
    cnt = max(tmp, cnt);
  }

  return cnt;
}

int main() {__
  int q;
  cin >> n >> m >> q;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> mat[i][j];
    }
  }

  vector<int> ans(n);
  for (int i = 0; i < n; ++i) {
    int res = countRow(i);
    ans[i]= res;
  }


  int x, y;
  for (int i = 0; i < q; ++i) {
    cin >> x >> y; x--; y--;
    mat[x][y] = !mat[x][y];
    int res = countRow(x);
    ans[x] = res;
    int mmax = *max_element(all(ans));
    cout << mmax << endl;
  }

  return 0;
}