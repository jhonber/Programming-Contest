// http://codeforces.com/contest/522/problem/A

#include<bits/stdc++.h>
using namespace std;

vector<int> G[222];
vector<int> visited(222);

string f(string s) {
  string ss;
  for (int i = 0; i < s.size(); ++i) ss += tolower(s[i]);
  return ss;
}

int solve(int i) {
  queue<int> Q;
  Q.push(i);
  visited[i] = true;
  vector<int> cost(222, 0);

  while (!Q.empty()) {
    int v = Q.front(); Q.pop();

    for (int j = 0; j < G[v].size(); ++j) {
      int cur = G[v][j];
      if (!visited[cur]) {
        visited[cur] = true;
        Q.push(cur);
        cost[cur] = cost[v] + 1;
      }
    }
  }

  return *max_element(cost.begin(), cost.end()) + 1;
}

int main() {
  int n;
  cin >> n;

  int ind = 0;
  map<string, int> getInd;

  for (int i = 0; i < n; ++i) {
    string a, b, c;
    cin >> a >> b >> c;
    a = f(a);
    c = f(c);
    if (!getInd[a]) getInd[a] = ++ ind;
    if (!getInd[c]) getInd[c] = ++ ind;
    int ii = getInd[c];
    int jj = getInd[a];
    G[ii].push_back(jj);
  }

  cout << solve(getInd["polycarp"]);
  return 0;
}