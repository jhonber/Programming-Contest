#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

struct STATE {
  string s;
  int cnt;
  int steps;
  STATE (){}
  STATE (string a, int b, int c) {
    s = a;
    cnt = b;
    steps = c;
  }
};

int count (string s) {
  int t = 0;
  for (int i = 0; i < s.size(); ++i) if (s[i] == '+') t ++;
  return t;
}

void solve (string s, int k) {
  queue<STATE> Q;
  int tot = count(s);
  Q.push(STATE(s, tot, 0));
  unordered_set<string> visited;

  while (!Q.empty()) {
    STATE cur = Q.front(); Q.pop();
    if (cur.cnt == cur.s.size()) {
      cout << cur.steps << endl;
      return;
    }

    if (visited.count(cur.s) == 0) {
      visited.insert(cur.s);

      for (int i = 0; i + k <= s.size(); ++i) {
        string tmp = cur.s;
        tot = cur.cnt;
        for (int j = 0; j < k; ++j) {
          int ind = i + j;
          if (tmp[ind] == '+') {
            tmp[ind] = '-';
            tot --;
          }
          else {
            tmp[ind] = '+';
            tot ++;
          }
        }

        Q.push(STATE(tmp, tot, cur.steps + 1));
      }

    }
  }

  cout << "IMPOSSIBLE" << endl;
}

int main() {
  int t, TC = 1;
  cin >> t;

  while (t --> 0) {
    string s;
    int k;
    cin >> s >> k;

    cout << "Case #" << TC ++ << ": ";
    solve(s, k);
  }

  return 0;
}
