// http://codeforces.com/contest/131/problem/B

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

int main() {__
  int n;
  cin >> n;

  map<int, bool> mark;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
    mark[v[i]] = true;
  }

  int psum[22][111111];
  memset(psum, 0, sizeof psum);

  for (int i = -10; i <= 10; ++i) {
    if (mark[i]) {
      for (int j = 0; j < n; ++j) {
        if (v[j] == i) psum[i + 10][j + 1] += psum[i + 10][j] + 1;
        else psum[i + 10][j + 1] += psum[i + 10][j];
      }
    }
  }

  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    int j = - v[i] + 10;
    ans += psum[j][n] - psum[j][i + 1];
  }

  cout << ans;
  return 0;
}