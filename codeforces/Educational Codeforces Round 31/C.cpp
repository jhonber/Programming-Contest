// http://codeforces.com/contest/884/problem/C

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

vector<int> G[123456];
void get_size (int &i, vector<int> &visited, int &size) {
  if (!visited[i]) {
    visited[i] = true;
    for (int j = 0; j < G[i].size(); ++j) {
      size ++;
      get_size(G[i][j], visited, size);
    }
  }
}

long long calc (long long i) {
  return i * i;
}

int main() {
  int n;
  while (cin >> n) {
    for (int i = 0; i < n; ++i) {
      int a;
      cin >> a;
      G[i + 1].push_back(a);
    }

    vector<long long> sizes;
    vector<int> visited(123456, 0);
    for (int i = 1; i <= n; ++i) {
      if (!visited[i]) {
        int size = 0;
        get_size(i, visited, size);
        sizes.push_back(size);
      }
    }

    sort(sizes.begin(), sizes.end());
    int t = sizes.size();
    long long ans = 0;
    if (t == 1) {
      ans = calc(sizes[0]);
    }
    else {
      ans = calc(sizes[t - 1] + sizes[t - 2]);
    }

    for (int i = 0; i + 2 < t; ++i) {
      ans += calc(sizes[i]);
    }

    cout << ans << endl;
  }

  return 0;
}