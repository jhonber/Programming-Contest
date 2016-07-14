// http://codeforces.com/contest/697/problem/C

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long L;

unordered_map<string, L> edges;

string make_key(L u, L v) {
  stringstream ss;
  string key;

  ss << u;
  ss << "-";
  ss << v;
  ss >> key;

  return key;
}

void update (L &u, L &v, L &val) {
  if (u == v) return;

  if (u < v) swap(u, v);
  L p = u >> 1LL;

  string k1 = make_key(p, u);
  string k2 = make_key(u, p);

  if (edges.count(k1) > 0) {
    edges[k1] += val;
  }
  else if (edges.count(k2) > 0) {
    edges[k2] += val;
  }
  else {
    edges[k1] = val;
  }

  update(p, v, val);
}

L calculate (L u, L v) {
  if (u == v) return 0LL;

  L tot = 0;
  if (u < v) swap(u, v);
  L p = u >> 1;

  string k1 = make_key(p, u);
  string k2 = make_key(u, p);

  if (edges.count(k1) > 0) {
    tot += edges[k1];
  }
  else if (edges.count(k2) > 0) {
    tot += edges[k2];
  }

  tot += calculate(p, v);

  return tot;
}

int main() {
  int q;
  cin >> q;

  while (q --> 0) {
    int op;
    cin >> op;

    if (op == 1) {
      L u, v, val;
      cin >> u >> v >> val;
      update(u, v, val);
    }
    else {
      L u, v;
      cin >> u >> v;
      cout << calculate(u, v) << endl;
    }
  }

  return 0;
}