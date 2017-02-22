// http://codeforces.com/contest/768/problem/C

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
  #ifdef ONLINE_JUDGE
    IO
  #endif
  int n, k, x;
  while (cin >> n >> k >> x) {
    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    sort(v.begin(), v.end());

    if (k == 0) {
      cout << v[n - 1] << " " << v[0] << endl;
      continue;
    }

    int r;
    int size = 0;
    map<vector<int>, int> ready;
    vector<vector<int>> mat;
    for (int i = 0; ; ++i) {
      for (int j = 0; j < n; j += 2) {
        v[j] ^= x;
      }

      sort(v.begin(), v.end());

      if (ready.count(v) > 0) {
        size = mat.size() - ready[v];
        r = ready[v];
        break;
      }

      mat.push_back(v);
      ready[v] = i;
    }

    int ind = k - 1;
    if (k > r) {
      k -= r;
      k = (((k % size) - 1) + size) % size;
      ind = k + r;
    }

    cout << mat[ind][n - 1] << " " << mat[ind][0] << endl;
  }

  return 0;
}
