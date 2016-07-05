#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;
#define IO ios::sync_with_stdio(false); cin.tie(NULL);

int main() { IO
  int n, m;
  while (cin >> n >> m) {

    map<int, int> mapa;
    for (int i = 0; i < n; ++i) {
      int a;
      cin >> a;
      mapa[a] ++;

    }

    vector<int> v(m);
    for (int i = 0; i < m; ++i) cin >> v[i];

    reverse(v.begin(), v.end());

    int ans = 0;
    while (v.size() > 0) {
      int cur = v.back(); v.pop_back();

      int mx = 0;
      int mm = 0;
      for (auto i: mapa) {
        if (i.first <= cur && i.first > mx) {
          mx = i.first;
        }
        mm = max(i.first, mm);
      }

      if (!mx) {
        int other = mm - cur;
        mapa[mm] --;
        if (mapa[mm] == 0) mapa.erase(mm);
        mapa[other] ++;
      }
      else {
        mapa[mx] --;
        if (mapa[mx] == 0) mapa.erase(mx);
        ans ++;
      }
    }

    cout << ans << endl;
  }

  return 0;
}