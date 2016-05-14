#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define D(x) cout << #x << " = " << (x) << endl;
#define endl '\n'

int main() {
  int t;
  cin >> t;

  int cnt = 0;
  while (t --> 0) {
    int n, m;
    cin >> n >> m;

    if (cnt > 0) cout << endl;

    vector<int> v[n + 1];
    for (int i = 0; i < m; ++i) {
      int x;
      cin >> x;
      v[x % n].push_back(x);
    }

    for (int i = 0; i < n; ++i) {
      cout << i << " -> ";
      for (int j = 0; j < v[i].size(); ++j) {
        cout << v[i][j] << " -> ";
      }

      cout << "\\" << endl;
    }

    cnt ++;
  }

  return 0;
}