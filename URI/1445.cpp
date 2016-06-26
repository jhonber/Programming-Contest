#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

vector<int> G[1010];
vector<int> visited(1010);

void solve(int x, int &ans) {
  if (!visited[x]) {
    visited[x] = true;
    ans ++;

    for (int i = 0; i < G[x].size(); ++i) {
      solve(G[x][i], ans);
    }
  }
}

int main() {
  string s;
  int n;
  while (getline(cin, s)) {
    n = atoi(s.c_str());
    if (!n) break;

    for (int i = 0; i < 1010; ++i) G[i].clear();
    for (int i = 0; i < 1010; ++i) visited[i] = 0;

    getline(cin, s);
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '(' || s[i] == ')' || s[i] == ',')
        s[i] = ' ';
    }

    stringstream ss;
    ss << s;

    int a;
    vector<int> v;
    while (ss >> a) {
      v.push_back(a);
    }

    for (int i = 0; i < v.size(); i += 2) {
      G[v[i]].push_back(v[i + 1]);
      G[v[i + 1]].push_back(v[i]);
    }

    int ans = 0;
    solve(1, ans);
    cout << ans << endl;
  }

  return 0;
}