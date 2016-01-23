// http://codeforces.com/contest/617/problem/D

#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define D(x) cout << #x << " = " << endl;

int main() {
  pair<int, int> a,b,c;

  cin >> a.first >> a.second >> b.first >> b.second >> c.first >> c.second;

  int ans = INT_MAX;
  // x
  set<int> x1;
  x1.insert(a.first);
  x1.insert(b.first);
  x1.insert(c.first);

  ans = min(ans, (int)x1.size());

  // y
  set<int> y1;
  y1.insert(a.second);
  y1.insert(b.second);
  y1.insert(c.second);

  ans = min(ans, (int)y1.size());

  if (ans == 1) {
    cout << 1;
    return 0;
  }

  if (a.first == b.first && b.first != c.first) {
    int ymm = min(a.second, b.second);
    int ymx = max(a.second, b.second);

    if (c.second > ymm && c.second < ymx) cout << 3;
    else cout << 2;
    return 0;
  }

  if (a.first == c.first && a.first != b.first) {
    int ymm = min(a.second, c.second);
    int ymx = max(a.second, c.second);

    if (b.second > ymm && b.second < ymx) cout << 3;
    else cout << 2;
    return 0;
  }

  if (c.first == b.first && c.first != a.first) {
    int ymm = min(b.second, c.second);
    int ymx = max(b.second, c.second);

    if (a.second > ymm && a.second < ymx) cout << 3;
    else cout << 2;
    return 0;
  }


  // --
  if (a.second == b.second && b.second != c.second) {
    int ymm = min(a.first, b.first);
    int ymx = max(a.first, b.first);

    if (c.first > ymm && c.first < ymx) cout << 3;
    else cout << 2;
    return 0;
  }

  if (a.second == c.second && a.second != b.second) {
    int ymm = min(a.first, c.first);
    int ymx = max(a.first, c.first);

    if (b.first > ymm && b.first < ymx) cout << 3;
    else cout << 2;
    return 0;
  }

  if (c.second == b.second && c.second != a.second) {
    int ymm = min(b.first, c.first);
    int ymx = max(b.first, c.first);

    if (a.first > ymm && a.first < ymx) cout << 3;
    else cout << 2;
    return 0;
  }

  cout << 3;

  return 0;
}