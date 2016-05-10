#include<bits/stdc++.h>
using namespace std;

#define D(x) //cout << #x << " = " << (x) << endl;

int toInt (string num) {
  int n;
  stringstream ss;
  ss << num;
  ss >> n;
  return n;
}

int is_digit(char c) {
  return c != '(' && c != ')' && c != ' ';
}

int main() {
  string line;
  while (getline(cin, line)) {
    vector<set<int>> G(100 + 1);
    queue<int> Q;
    Q.push(1);

    while (!Q.empty()) {
      int cur = Q.front(); Q.pop();
      int cnt = 0;
      int a, b;
      int size = 1;
      if (is_digit(line[cur + 1])) size ++;
      a = toInt(line.substr(cur, size));

      for (int i = cur; i < line.size(); ++i) {
        if (cnt < 0) break;
        if (line[i] == ' ') continue;

        if (line[i] == '(') cnt ++;

        if (cnt == 1 && is_digit(line[i])) {
          Q.push(i);

          int f = false;
          int size = 1;
          if (isdigit(line[i + 1])) {
            size ++;
            f = true;
          }

          b = toInt(line.substr(i, size));
          G[a].insert(b);
          G[b].insert(a);
          if (f) i ++;
        }

        if (line[i] == ')') cnt --;
      }
    }

    int n = 0;
    for (int i = 0; i < G.size(); ++i) if (G[i].size() > 0) n ++;

    if (n > 1) {
      vector<int> ans;
      int found = true;

      while (found) {
        int mm = INT_MAX;
        for (int i = 1; i <= n; ++i) if (G[i].size() == 1) {
          mm = min(mm, i);
        }

        found = false;
        for (int i = 1; i <= n; ++i) if (G[i].count(mm) > 0) {
          G[i].erase(mm);
          G[mm].erase(i);
          ans.push_back(i);
          found = true;
          break;
        }
      }

      cout << ans[0];
      for (int i = 1; i < ans.size(); ++i) cout << " " << ans[i]; cout << endl;
    }
    else cout << endl;
  }
  return 0;
}