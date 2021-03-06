// http://codeforces.com/contest/714/problem/C

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

const int MN = 2; // size of alphabet
const int MS = 600600; // Number of states.

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

  int ope (const string &s, int val, bool query = 0) {
    int cur_node = 0;
    for (int i = 0; i < s.size(); ++i) {
      int id = s[i] - '0';
      if (tree[cur_node].a[id] == -1) {
        if (query) return 0;
        tree[cur_node].a[id] = nodes;
        clear();
      }
      cur_node = tree[cur_node].a[id];
    }
    if (!query) tree[cur_node].c += val;
    return tree[cur_node].c;
  }

};

void normalize (string &s) {
  while (s.size() < 18) s += "0";
}

int main() {
  int t;
  cin >> t;

  trie tree;
  tree.init();

  while (t --> 0) {
    char op;
    long long val;
    string x;

    cin >> op;
    if (op != '?') {
      cin >> val;

      string s;
      if (val == 0) s += "0";
      while (val) {
        s += ((val % 10) % 2 ? "1" : "0");
        val /= 10;
      }

      normalize(s);
      reverse(s.begin(), s.end());

      if (op == '+') {
        tree.ope(s, 1, 0);
      }
      else {
        tree.ope(s, -1, 0);
      }
    }
    else {
      cin >> x;

      reverse(x.begin(), x.end());
      normalize(x);
      reverse(x.begin(), x.end());

      cout << tree.ope(x, 0, 1) << endl;
    }
  }

  return 0;
}