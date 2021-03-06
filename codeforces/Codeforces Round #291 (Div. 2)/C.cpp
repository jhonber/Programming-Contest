// http://codeforces.com/contest/514/problem/C

#include<bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define foreach(it, x) for (__typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define all(x) x.begin(),x.end()
#define D(x) cout << #x " = " << (x) << endl;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

int dx[8] = {-1,-1,-1,0,1,1, 1, 0};
int dy[8] = {-1, 0, 1,1,1,0,-1,-1};

const int inf = INT_MAX;
const int MN = 3; // size of alphabet
const int MS = 600010; // Number of states.

struct trie {
  struct node {
    int c;
    int a[MN];
  };

  node tree[MS];
  int nodes;
  void clear() {
    tree[nodes].c = 0;
    memset(tree[nodes].a, -1, sizeof tree[nodes].a);
    nodes++;
  }

  void init() {
    nodes = 0;
    clear();
  }

  int add (const string &s, bool query = 0) {
    int cur_node = 0;
    for (int i = 0; i < s.size(); ++i) {
      int id = s[i] - 'a';
      if (tree[cur_node].a[id] == -1) {
        if (query) return 0;
        tree[cur_node].a[id] = nodes;
        clear();
      }
      cur_node = tree[cur_node].a[id];
    }
    if (!query) tree[cur_node].c++;
    return tree[cur_node].c;
  }

  bool exista (char *s, int cur_node, int changed) {
    if (cur_node == -1) return false;
    if (s[0] != 'a' && s[0] != 'b' && s[0] != 'c') {
      if (changed && tree[cur_node].c) return true;
      return false;
    }

    if (changed == 1) {
      return exista (s + 1, tree[cur_node].a[s[0] - 'a'], changed);
    }

    int rez = 0;
    for (int i = 0; i < 3; ++i) {
      char c = i + 'a';
      int tmp = tree[cur_node].a[i];
      if (c == s[0]) rez += exista (s + 1, tmp, 0);
      else rez += exista (s + 1, tmp, 1);
    }
    return rez;
  }
};

int main() {__
  int n,m;
  cin >> n >> m;

  trie tree;
  tree.init();
  char s[MS];
  for (int i = 0; i < n; ++i) {
    cin >> s;
    tree.add(s);
  }

  for (int i = 0; i < m; ++i) {
    cin >> s;
    if (tree.exista(s,0,0)) cout << "YES" << endl;
    else cout << "NO" << endl;
  }

  return 0;
}