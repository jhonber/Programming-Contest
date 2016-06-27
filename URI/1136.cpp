#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n, m;

  while (cin >> n >> m) {
    if (!n) break;

    vector<int> arr(m);
    for (int i = 0; i < m; ++i) cin >> arr[i];

    vector<int> v(n + 1, 1);
    for (int i = 0; i < m; ++i) {
      for (int j = i + 1; j < m; ++j) {
        int d = abs(arr[i] - arr[j]);
        v[d] = false;
      }
    }

    int tot = accumulate(v.begin(), v.end(), 0);
    cout << (tot == 1 ? "Y" : "N") << endl;
  }
  return 0;
}