// http://codeforces.com/contest/792/problem/D

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

struct state {
  long long val, p, dir;
  state() {}
  state(long long a, long long b, long long c) {
    val = a;
    p = b;
    dir = c;
  }
};

ostream& operator << (ostream& out, state x) {
  return out << x.val << ", " << x.p << ", " << x.dir << endl;
}

map<long long, int> visited;

state go_to_k (state cur, long long k) {
  if (k == cur.val) return cur;

  long long bef = cur.val;
  if (k < cur.val) {
    cur.val -= cur.p / 2;
    cur.dir = -1;
  }
  else {
    cur.val += cur.p / 2;
    cur.dir = 1;
  }

  visited[cur.val] = cur.dir;
  cur.p /= 2;
  return go_to_k(cur, k);
}

long long process (string &s, state cur) {
  //cout << cur << endl;
  if (s.size() == 0) return cur.val;

  state bef = cur;
  char next = s.back();
  //D(next)
  s.pop_back();

  if (next == 'U') {
    if (cur.dir != 0) {
      if (cur.dir > 0)
        cur.val -= cur.p;
      else
        cur.val += cur.p;

      cur.dir = visited[cur.val];
      cur.p *= 2;
    }
  }
  else {
    if (cur.p != 1){
      if (next == 'L') {
        cur.val -= cur.p / 2;
        cur.dir = -1;
      }
      else {
        cur.val += cur.p / 2;
        cur.dir = 1;
      }

      cur.p /= 2;
      visited[cur.val] = cur.dir;
    }
  }

  return process (s, cur);
}

int main() {
  long long n, q, k;
  cin >> n >> q;

  for (long long i = 0; i < q; ++i) {
    long long k;
    string s;
    cin >> k >> s;

    reverse(s.begin(), s.end());
    long long cur = (n + 1) / 2;
    state init = state(cur, cur, 0);
    visited[cur] = init.dir;
    state from = go_to_k(init, k);
    long long ans = process(s, from);
    cout << ans << endl;
  }

  return 0;
}