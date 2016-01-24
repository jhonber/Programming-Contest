// http://codeforces.com/contest/617/problem/D

#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define D(x) cout << #x << " = " << endl;

struct p {
  int x, y;
};

int main() {
  vector<p> v(3);
  cin >> v[0].x >> v[0].y >> v[1].x >> v[1].y >> v[2].x >> v[2].y;

  if (v[0].x == v[1].x && v[0].x == v[2].x || v[0].y == v[1].y && v[0].y == v[2].y) {
    cout << 1;
    return 0;
  }

  vector<int> ind = {0, 1, 2};
  do {
    if (v[ind[0]].x == v[ind[1]].x && v[ind[0]].x != v[ind[2]].x) {
      int mx = max(v[ind[0]].y, v[ind[1]].y);
      int mm = min(v[ind[0]].y, v[ind[1]].y);
      if (v[ind[2]].y > mm && v[ind[2]].y < mx ) cout << 3;
      else cout << 2;
      return 0;
    }

    if (v[ind[0]].y == v[ind[1]].y && v[ind[0]].y != v[ind[2]].y) {
      int mx = max(v[ind[0]].x, v[ind[1]].x);
      int mm = min(v[ind[0]].x, v[ind[1]].x);

      if (v[ind[2]].x > mm && v[ind[2]].x < mx ) cout << 3;
      else cout << 2;
      return 0;
    }
  } while (next_permutation(ind.begin(), ind.end()));

  cout << 3;
  return 0;
}