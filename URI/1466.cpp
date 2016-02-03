#include<bits/stdc++.h>
using namespace std;

struct node {
  int val;
  int l;
  int r;

  node () {
    val = l = r = -1;
  }
  node (int x) {
    val = x;
    l = r = -1;
  }
};

void insert(int i, int val, vector<node> &G) {
  if (val < G[i].val) {
    if (G[i].l == -1) {
      int id = G.size();
      G[i].l = id;
      G.emplace_back(val);
      return;
    }
    else {
      insert(G[i].l, val, G);
    }
  }
  else {
    if (G[i].r == -1) {
      int id = G.size();
      G[i].r = id;
      G.emplace_back(val);
      return;
    }
    else {
      insert(G[i].r, val, G);
    }
  }
}

void solve(vector<node> G) {
  queue<node> Q;
  Q.push(G[0]);

  vector<int> ans;
  while (!Q.empty()) {
    node cur = Q.front(); Q.pop();
    ans.push_back(cur.val);

    if (cur.l!= -1) {
      Q.push(G[cur.l]);
    }

    if (cur.r!= -1) {
      Q.push(G[cur.r]);
    }
  }

  for (int i = 0; i < ans.size(); ++i) {
    if (i > 0) cout << " ";
    cout << ans[i];
  }
}

int main() {
  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) {
    int n, r;
    cin >> n >> r;

    vector<node> G;
    G.emplace_back(r);

    for (int j = 1; j < n; ++j) {
      int a;
      cin >> a;
      insert(0, a, G);
    }

    cout << "Case " << i + 1 << ":" << endl;
    solve(G);
    cout << endl << endl;
  }

  return 0;
}
