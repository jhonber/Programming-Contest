// http://codeforces.com/contest/554/problem/B

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

void make (vector<string> &v, int c) {
  for (int i = 0; i < v.size(); ++i) {
    v[i][c] = (v[i][c] == '0' ? '1' : '0');
  }
}

int count (vector<string> &v) {
  int rez = 0;
  for (int i = 0; i < v.size(); ++i) {
    int f = true;
    for (int j = 0; j < v.size(); ++j) {
      if (v[i][j] == '0') f = false;
    }
    rez += f;
  }
  return rez;
}

int main() {
  int n;
  cin >> n;

  vector<string> v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];

  int ans = count(v);
  for (int i = 0; i < n; ++i) {
    vector<string> vv = v;
    for (int j = 0; j < n; ++j) {
      if (vv[i][j] == '0') make (vv, j);
    }
    int t = count (vv);
    ans = max(ans, t);
  }

  cout << ans;

  return 0;
}