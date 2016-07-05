#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) //cout << #x << " = " << (x) << endl;
#define IO ios::sync_with_stdio(false); cin.tie(NULL);

int main() { IO
  int t;
  cin >> t;

  while (t --> 0) {
    int a, b, c;
    cin >> a >> b >> c;

    vector<int> v(105, -1);
    for (int i = 0; i < b; ++i) {
      int x, y;
      cin >> x >> y;

      v[x] = y;
    }

    unordered_map<int, int> pos;
    for (int i = 1; i <= a; ++i) pos[i] = 1;

    int x;
    int end = false;
    int p = 1;
    for (int i = 0; i < c; ++i, ++p) {
      cin >> x;

      if (end) continue;
      if (p > a) p = 1;

      while (true) {
        pos[p] += x;
        pos[p] = min(pos[p], 100);

        if (pos[p] == 100) {
          end = true;
          break;
        }

        if (v[pos[p]] != -1) {
          pos[p] = min(v[pos[p]], 100);
        }

        if (pos[p] == 100) {
          end = true;
          break;
        }

        if (v[pos[p]] == -1) break;
      }
    }

    for (int i = 1; i <= a; ++i)
      cout << "Position of player " << i << " is " << pos[i] << "." << endl;
  }

  return 0;
}