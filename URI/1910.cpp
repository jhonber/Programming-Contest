#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

struct node {
  int val;
  int cost;
  node() {}
  node(int a_, int b_): val(a_), cost(b_) {}
};

int solve(int x, int y, set<int> banned) {
  queue<node> Q;
  Q.push(node(x, 0));

  vector<int> visited(111000, 0);
  while (!Q.empty()) {
    node cur = Q.front(); Q.pop();

    if (banned.count(cur.val) > 0) continue;
    if (cur.val == y) return cur.cost;

    if (!visited[cur.val]) {
      visited[cur.val] = true;

      int v = cur.val;
      int step[] = {v + 1, v - 1, v * 2, v * 3};

      for (int i = 0; i < 4; ++i) {
        if (step[i] > 0 && step[i] <= 1e5) {
          Q.push(node(step[i], cur.cost + 1));
        }
      }

      if (v % 2 == 0 && v / 2 > 0) {
        Q.push(node(v / 2, cur.cost + 1));
      }
    }
  }

  return -1;
}

int main() {
  int x, y, k;
  while (cin >> x >> y >> k) {
    if (x + y + k == 0) break;

    set<int> st;
    for (int i = 0; i < k; ++i) {
      int a;
      cin >> a;
      st.insert(a);
    }

    cout << solve(x, y, st) << endl;
  }

  return 0;
}