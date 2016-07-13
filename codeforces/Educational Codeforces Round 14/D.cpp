// http://codeforces.com/contest/691/problem/D

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() { IO
  int n, m;
  cin >> n >> m;

  vector<int> v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];

  vector<int> G[n + 1];
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b; a--; b --;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  vector<int> visited(n, 0);
  for (int i = 0; i < n; ++i) {
    vector<int> nums;
    set<int> pos;

    queue<int> Q;
    Q.push(i);

    while (!Q.empty()) {
      int cur = Q.front(); Q.pop();
      pos.insert(cur);

      for (int j = 0; j < G[cur].size(); ++j) {
        if (!visited[G[cur][j]]) {
          visited[G[cur][j]] = true;
          Q.push(G[cur][j]);
        }
      }
    }

    for (auto j: pos) {
      nums.push_back(v[j]);
    }

    sort(nums.begin(), nums.end());
    reverse(nums.begin(), nums.end());
    int x = 0;
    for (auto j: pos) {
      v[j] = nums[x ++];
    }
  }

  for (int i = 0; i < n; ++i) cout << v[i] << " "; cout << endl;

  return 0;
}