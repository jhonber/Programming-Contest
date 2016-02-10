#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'

struct node {
  int l, r, v;
  node() {}
  node(int x) {
    v = x;
    l = r = -1;
  }
};

vector<node> G;

void insert(int val, int i) {
  if (val > G[i].v) {
    if (G[i].r == -1) {
      int id = G.size();
      G[i].r = id;
      G.emplace_back(val);
    }
    else {
      insert(val, G[i].r);
    }
  }
  else {
    if (G[i].l == -1) {
      int id = G.size();
      G[i].l = id;
      G.emplace_back(val);
    }
    else {
      insert(val, G[i].l);
    }
  }
}

void pre_order(int i) {
  cout << " " << G[i].v;
  if (G[i].l != -1)
    pre_order(G[i].l);

  if (G[i].r != -1)
    pre_order(G[i].r);
}

void in_order(int i) {
  if (G[i].l != -1)
    in_order(G[i].l);

  cout << " " << G[i].v;
  if (G[i].r != -1)
    in_order(G[i].r);

}

void post_order(int i) {
  if (G[i].l != -1)
    post_order(G[i].l);

  if (G[i].r != -1)
    post_order(G[i].r);

  cout << " " << G[i].v;
}

int main() { IO
  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) {
    int n;
    cin >> n;

    G.clear();
    for (int j = 0; j < n; ++j) {
      int a;
      cin >> a;

      if (j == 0) {
        G.emplace_back(a);
      }
      else {
        insert(a, 0);
      }
    }

    cout << "Case " << i + 1 << ":" << endl;
    cout << "Pre.:";
    pre_order(0);
    cout << endl;

    cout << "In..:";
    in_order(0);
    cout << endl;

    cout << "Post:";
    post_order(0);
    cout << endl << endl;
  }

  return 0;
}