#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'

const int mx = 1e5 + 10;
int p[mx];
int score[mx];

void init_set() {
  for (int i = 0; i < mx; ++i) p[i] = i;
}

int find_set (int x) {
  return p[x] == x ? p[x] : p[x] = find_set(p[x]);
}

void join (int x, int y) {
  p[find_set(x)] = find_set(y);
  int sum = score[x] + score[y];
  score[x] = score[y] = sum;
}

int main() { IO
  int n, m;
  while (cin >> n >> m) {
    if (n + m == 0) break;

    init_set();
    for (int i = 1; i <= n; ++i) cin >> score[i];

    int ans = 0;
    int q, a, b;
    for (int i = 0; i < m; ++i) {
      cin >> q >> a >> b;


      if (q == 1) {
        int s = find_set(a);
        if (s == 1) swap (a, b);
        join(a, b);
      }
      else {
        int sc1 = score[find_set(a)];
        int sc2 = score[find_set(b)];
        if (sc1 == sc2) continue;

        if (sc1 > sc2) {
          int s = find_set(a);
          if (s == 1) ans ++;
        }
        else if (sc2 > sc1) {
          int s = find_set(b);
          if (s == 1) ans ++;
        }
      }
    }

    cout << ans << endl;
  }

  return 0;
}
