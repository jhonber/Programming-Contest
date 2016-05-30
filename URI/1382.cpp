#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() { IO
  int t;
  cin >> t;

  while (t --> 0) {
    int n;
    cin >> n;

    map<int, int> mapa;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
      cin >> v[i];
      mapa[v[i]] = i;
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
      int cur = v[i];
      if (cur != i + 1) {
        ans ++;
        int other = mapa[i + 1];

        mapa[v[i]] = other;
        mapa[i + 1] = i;

        swap(v[i], v[other]);
      }
    }

    cout << ans << endl;
  }

  return 0;
}