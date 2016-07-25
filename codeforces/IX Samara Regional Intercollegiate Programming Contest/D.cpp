// http://codeforces.com/problemset/gymProblem/100971/D

#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  cin >> n;


  map<int, int> keys;
  map<int, int> dist_pop, pop_dist;
  set<int> pop;
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    keys[a] = i + 1;
    dist_pop[a] = b;
    pop_dist[b] = a;
    pop.insert(b);
  }

  if (n == 1) {
    cout << -1 << endl;
    return 0;
  }

  dist_pop[-INT_MAX] = 0;
  dist_pop[INT_MAX] = 0;

  vector<int> ans(n, -1);
  pair<int, int> a, b;
  for (auto p: pop) {
    int d = pop_dist[p];
    dist_pop.erase(d);

    auto up = dist_pop.upper_bound(d);

    b = *up;
    up --;
    a = *up;

    if (a.first == -INT_MAX) a.first = INT_MAX;

    int d1, d2;
    d1 = abs(a.first - d);
    d2 = abs(b.first - d);

    if (d1 == d2) {
      if (a.second < b.second) {
        swap(a, b);
      }
    }
    else if (d1 > d2) {
      swap(a, b);
    }

    ans[keys[d] - 1] = keys[a.first];
    if (dist_pop.size() == 3) break;
  }

  for (int i = 0; i < n; ++i) cout << ans[i] << " "; cout << endl;
  return 0;
}
