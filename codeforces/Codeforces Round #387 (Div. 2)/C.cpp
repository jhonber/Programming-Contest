// http://codeforces.com/contest/747/problem/C

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

struct task {
  int t, k, d;
  task () {}
  task (int a, int b, int c) {
    t = a;
    k = b;
    d = c;
  }
};

int main() {
  int n, q;
  cin >> n >> q;

  vector<task> v(q);

  int a, b, c;
  for (int i = 0; i < q; ++i) {
    cin >> a >> b >> c;
    v[i] = task(a, b, c);
  }

  reverse(v.begin(), v.end());

  vector<int> servers(n, 0);
  for (int i = 1; i <= 1e6 + 3333; ++i) {
    if (v.size()) {
      task cur = v.back();
      a = cur.t;
      b = cur.k;
      c = cur.d;

      if (a == i) {
        int free = 0;
        for (int j = 0; j < servers.size(); ++j) {
          if (!servers[j]) free ++;
        }

        int tot = b;
        int sum = 0;
        if (free >= b) {
          for (int j = 0; j < servers.size() && tot > 0; ++j) {
            if (servers[j] == 0) {
              servers[j] = c;
              sum += j + 1;
              tot --;
            }
          }

          cout << sum << endl;
        }
        else {
          cout << -1 << endl;
        }

        v.pop_back();
      }
    }

    for (int j = 0; j < servers.size(); ++j) {
      if (servers[j] > 0) servers[j] --;
    }
  }

  return 0;
}