// https://csacademy.com/contest/virtual6147/task/prefix-free-subset/statistics/

#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;
#define endl '\n'

const int inf = INT_MAX;
const int MN = 30; // size of alphabet
const int MS = 1000100; // Number of states.

struct trie {
  struct node {
    int c;
    int a[MN];
  };

  node tree[MS];
  int leafs;
  int nodes;
  int best;
  void clear() {
    tree[nodes].c = 0;
    memset(tree[nodes].a, -1, sizeof tree[nodes].a);
    nodes++;
  }

  void init() {
    nodes = 0;
    leafs = 0;
    best  = 0;
    clear();
  }

  int add (const string &s, bool query = 0) {
    int cur_node = 0;
    bool pre = false;
    bool diff = false;
    best = max(best, (int)s.size());
    for (int i = 0; i < s.size(); ++i) {
      int id = s[i] - 'a';
      if (tree[cur_node].a[id] == -1) {
        diff = true;
        if (query) return 0;
        tree[cur_node].a[id] = nodes;
        clear();
      }
      else if (tree[tree[cur_node].a[id]].c > 0) {
        tree[tree[cur_node].a[id]].c = 0;
        pre = true;
      }
      cur_node = tree[cur_node].a[id];
    }
    if (diff) leafs ++;
    if (pre) leafs --;
    if (!query) tree[cur_node].c++;
    return leafs;
  }

};

bool cmp (string &a, string &b) {
  if (a.size() == b.size()) {
    return a < b;
  }

  return a.size() < b.size();
}

int main() {
  int n, k;
  cin >> n >> k;

  vector<string> v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];

  sort(v.begin(), v.end(), cmp);
  v.erase(unique(v.begin(), v.end()), v.end());

  trie tree;
  tree.init();

  bool ok = false;
  for (int i = 0; i < v.size(); ++i) {
    int leafs = tree.add(v[i]);
    if (leafs == k) {
      cout << tree.best << endl;
      ok = true;
      break;
    }
  }

  if (!ok) cout << -1 << endl;

  return 0;
}
