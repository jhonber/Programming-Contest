#include<bits/stdc++.h>
using namespace std;

struct data {
  int x;
  int c;
  data () {}

  data (int _x) {
    x = _x;
    c = 0;
  }

  data (int _x, int _c) {
    x = _x;
    c = _c;
  }

};

int pot(int n) {
  int p = 1;
  while (n > 0) {
    n /= 10;
    p *= 10;
  }

  return p / 10;
}

int rev_int(int n) {
  int r = 0;
  int p = pot(n);
  while (n > 0) {
    r += (n % 10) * p;
    n /= 10;
    p /= 10;
  }

  return r;
}

int solve(int a, int b) {

  queue<data> Q;
  Q.push(data(a));

  map<int, bool> visited;
  visited[a] = true;
  while (!Q.empty()) {
    data cur = Q.front(); Q.pop();

    if (cur.x == b) return cur.c;

    int other = rev_int(cur.x);
    if (!visited[other]) {
      visited[other] = true;
      Q.push(data(other, cur.c + 1));
    }

    cur.x ++;
    cur.c ++;
    if (!visited[cur.x]) {
      visited[cur.x] = true;
      Q.push(cur);
    }
  }
}


int main() {
  int t;
  cin >> t;

  int a, b;
  for (int i = 0; i < t; ++i) {
    cin >> a >> b;

    cout << solve(a, b) << endl;
  }

  return 0;
}