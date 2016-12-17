#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

string make_key(int a, int b, int c) {
  string k = to_string(a) + to_string(b) + to_string(c);
  return k;
}

int main() { IO
  int tc, n, q;
  cin >> tc;

  while (tc --> 0) {
    cin >> n;

    unordered_map<string, int> mapa;
    vector<set<int>> v(n);
    for (int i = 0; i < n; ++i) {
      int t;
      cin >> t;

      for (int j = 0; j < t; ++j) {
        int a;
        cin >> a;
        v[i].insert(a);
      }
    }

    cin >> q;
    while (q --> 0) {
      int a, x, y;
      cin >> a >> x >> y; x --; y --;

      /*string key = make_key(a, x, y);
      if (mapa.count(key)) {
        cout << mapa[key] << endl;
        continue;
      }*/

      int ans = 0;
      if (a == 1) {
        for (auto i: v[x]) {
          if (v[y].count(i)) ans ++;
        }
      }
      else {
        set<int> st = v[x];
        st.insert(v[y].begin(), v[y].end());

        ans = st.size();
      }

      //mapa[key] = ans;
      cout << ans << endl;
    }
  }

  return 0;
}