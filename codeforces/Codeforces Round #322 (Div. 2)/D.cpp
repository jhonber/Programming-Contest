// http://codeforces.com/contest/581/problem/D

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

struct part {
  char c;
  int x;
  int y;
};

bool solve (vector<part> &v) {
  part a,b,c;
  a = v[0];
  b = v[1];
  c = v[2];

  int x = c.x;
  char ans[x][x];
  memset(ans, '*', sizeof ans);

  int f = false;
  if (a.x + b.x == c.x && a.y + c.y == c.x && a.y == b.y) {
    for (int i = 0; i < a.y; ++i) {
      for (int j = 0; j < a.x; ++j) {
        ans[i][j] = a.c;
      }
    }

    for (int i = 0; i < b.y; ++i) {
      for (int j = a.x; j < a.x + b.x; ++j) {
        ans[i][j] = b.c;
      }
    }

    for (int i = 0; i < x; ++i) {
      for (int j = 0; j < x; ++j) {
        if (ans[i][j] == '*') ans[i][j] = c.c;
      }
    }

    f = true;
  }

  if (a.x == b.x && b.x == c.x && a.y + b.y + c.y == a.x) {
    for (int i = 0; i < a.y; ++i) {
      for (int j = 0; j < x; ++j) {
        ans[i][j] = a.c;
      }
    }

    for (int i = a.y; i < a.y + b.y; ++i) {
      for (int j = 0; j < x; ++j) {
        ans[i][j] = b.c;
      }
    }

    for (int i = a.y + b.y; i < a.y + b.y + c.y; ++i) {
      for (int j = 0; j < x; ++j) {
        ans[i][j] = c.c;
      }
    }

    f = true;
  }

  if (f) {
    cout << x << endl;
    for (int i = 0; i < x; ++i) {
      for (int j = 0; j < x; ++j) {
        cout << ans[i][j];
      }
      cout << endl;
    }
    return true;
  }

  return false;
}

int main() {
  int n = 6;

  vector<part> v(n);
  for (int i = 0; i < n / 2; ++i) {
    part a;
    cin >> a.x >> a.y;
    a.c = char(i + 'A');
    v[i] = a;
  }

  vector<int> p = {0, 1, 2};
  do {
    vector<part> v2, tmp;
    v2.push_back(v[p[0]]);
    v2.push_back(v[p[1]]);
    v2.push_back(v[p[2]]);

    tmp = v2;
    for (int i = 0; i < 2; ++i) {
      v2 = tmp;
      for (int j = 0; j < 2; ++j) {
        v2 = tmp;
        for (int k = 0; k < 2; ++k) {
          v2 = tmp;
          if (i) swap(v2[p[0]].x, v2[p[0]].y);
          if (j) swap(v2[p[1]].x, v2[p[1]].y);
          if (k) swap(v2[p[2]].x, v2[p[2]].y);

          if (solve(v2)) return 0;
        }
      }
    }
  }
  while (next_permutation(all(p)));

  cout << -1;
  return 0;
}