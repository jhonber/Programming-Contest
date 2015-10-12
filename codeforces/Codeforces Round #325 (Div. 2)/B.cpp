// http://codeforces.com/contest/586/problem/B

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

  int mat[3][n];
  memset(mat, 0, sizeof mat);

  for (int i = 1; i < n; ++i) {
    int x;
    cin >> x;
    mat[0][i] = mat[0][i - 1] + x;
  }

  vector<int> tmp(n - 1);
  for (int i = 0; i < n - 1; ++i) {
    cin >> tmp[i];
  }

  for (int i = n - 2; i >= 0; --i) {
    mat[2][i] = mat[2][i + 1] + tmp[i];
  }

  for (int i = 0; i < n; ++i) {
    cin >> mat[1][i];
  }

  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    int tot = 0;
    for (int j = 0; j < 3; ++j) tot += mat[j][i];
    v[i] = tot;
  }

  sort(all(v));
  cout << v[0] + v[1];

  return 0;
}