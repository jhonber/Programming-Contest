#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;
#define endl '\n'

int main() {
  int cnt = 5;
  vector<int> v[cnt];
  for (int i = 0; i < cnt; ++i) {
    int n;
    cin >> n;
    for (int j = 0; j < n; ++j) {
      int a;
      cin >> a;
      v[i].push_back(a);
    }
  }

  int k;
  cin >> k;

  for (int i = 0; i < cnt; ++i) {
    sort(v[i].begin(), v[i].end());
  }

  vector<int> all;
  for (int i = 0; i < v[0].size(); ++i) {
    for (int j = 0; j < v[1].size(); ++j) {
      for (int k = 0; k < v[2].size(); ++k) {
        for (int l = 0; l < v[3].size(); ++l) {
          for (int m = 0; m < v[4].size(); ++m) {
            all.push_back(v[0][i] + v[1][j] + v[2][k] + v[3][l] + v[4][m]);
          }
        }
      }
    }
  }


  sort(all.begin(), all.end());
  reverse(all.begin(), all.end());

  int ans = 0;
  for (int i = 0; i < k; ++i) ans += all[i];
  cout << ans << endl;

  return 0;
}