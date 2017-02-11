// http://codeforces.com/contest/734/problem/D

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

const long long inf = LLONG_MAX;

struct Piece {
  long long x, y, t;
  Piece () {}
  Piece (long long a, long long b, long long c) {
    x = a;
    y = b;
    t = c;
  }
};

long long dist (long long x1, long long y1, long long x2, long long y2) {
  return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}

long long f (long long x, long long y, long long x2, long long y2, long long type, long long k) {
  long long d = dist (x, y, x2, y2);

  if (type == 1) if (x + k == x2 && y + k == y2) return d;
  if (type == 2) if (x - k == x2 && y - k == y2) return d;
  if (type == 3) if (x + k == x2 && y - k == y2) return d;
  if (type == 4) if (x - k == x2 && y + k == y2) return d;

  if (type == 5) if (x - k == x2 && y == y2) return d;
  if (type == 6) if (x + k == x2 && y == y2) return d;
  if (type == 7) if (x == x2 && y - k == y2) return d;
  if (type == 8) if (x == x2 && y + k == y2) return d;

  return inf;
}

int main() {
  int n;
  cin >> n;

  long long x, y;
  cin >> x >> y;

  vector<Piece> v;
  for (int  i = 0; i < n; ++i) {
    char op;
    cin >> op;

    long long x2, y2;
    cin >> x2 >> y2;
    if (op == 'Q') {
      v.push_back(Piece(x2, y2, 0));
    }
    else if (op == 'B') {
      v.push_back(Piece(x2, y2, 1));
    }
    else {
      v.push_back(Piece(x2, y2, 2));
    }
  }

  for (int j = 1; j <= 8; ++j) {
    long long mm = inf;
    bool found = false;
    Piece p;
    for (int i = 0; i < n; ++i) {
      long long a = f(x, y, v[i].x, v[i].y, j, abs(v[i].y - y));
      long long b = f(x, y, v[i].x, v[i].y, j, abs(v[i].x - x));
      long long tmp = min(a, b);

      if (tmp < mm) {
        mm = tmp;
        p = v[i];
        found = true;
      }
    }

    bool paila = false;
    if (found) {
      for (int i = 1; i <= 8; ++i) {
        if (p.t == 1 && i > 4) continue;
        if (p.t == 2 && i < 5) continue;

        long long a = f(p.x, p.y, x, y, i, abs(p.y - y));
        long long b = f(p.x, p.y, x, y, i, abs(p.x - x));
        long long tmp = min(a, b);
        if (tmp != inf) {
          paila = true;
          break;
        }
      }
    }

    if (paila) {
      cout << "YES" << endl;
      return 0;
    }
  }

  cout << "NO" << endl;

  return 0;
}