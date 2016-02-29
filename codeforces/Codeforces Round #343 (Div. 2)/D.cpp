// http://codeforces.com/contest/629/problem/D

#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define PI 3.141592653589793
#define D(x) cout << #x << " = " << (x) << endl;

struct seg_tree {
  vector<long long> tree;
  seg_tree (int n) {
    tree.assign(4 * n + 10, 0);
  }

  //              node,   0,     n,     a,     b
  long long query(int id, int x, int y, int l, int r) {
    if ( x >= l && y <= r)
      return tree[id];
    if (y < l || x > r ) return 0;

    int mid = (x + y) / 2;
    long long a = query(id * 2, x, mid, l, r);
    long long b = query(2 * id + 1, mid + 1, y, l, r);

    return  max(a, b);
  }

  void update (int id, int x, int y, int pos, long long val) {
    if (x == y) {
      tree[id] = val;
      return;
    }

    int mid = (x + y) / 2;
    if (mid >= pos) update(2 * id, x, mid, pos, val);
    else update(2 * id + 1, mid + 1, y, pos, val);

    tree[id] = max(tree[2 * id], tree[2 * id + 1]);
  }

};

int main() { IO
  int n;
  cin >> n;

  long long r, h;
  vector<long long> v(n);
  set<long long> st;
  for (int i = 0; i < n; ++i) {
    cin >> r >> h;
    v[i] = r * r * h;
    st.insert(v[i]);
  }

  map<long long, int> key;
  int ind = 1;
  for (auto i : st) {
    key[i] = ind;
    ind ++;
  }

  long long dp[n + 10];
  dp[0] = 0;

  int m = n + 1;
  seg_tree tree(m);

  for (int i = 1; i <= n; ++i) {
    int j = i - 1;
    dp[i] = tree.query(1, 0, m, 0, key[v[j]] - 1) + v[j];
    tree.update(1, 0, m, key[v[j]], dp[i]);
  }

  long long ans = tree.query(1, 0, m, 0, m);
  cout << fixed << setprecision(12) << (double)ans * PI << endl;

  return 0;
}