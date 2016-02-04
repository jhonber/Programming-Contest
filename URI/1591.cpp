#include<bits/stdc++.h>
using namespace std;

int count (string s, string r) {
  int pos = 0;
  int tot = 0;
  while (s.find(r, pos) != string::npos) {
    int ind = s.find(r, pos);
    pos = ind + 1;
    tot ++;
  }

  return tot;
}

int main() {
  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) {
    int n, m;
    cin >> n >> m;

    map<char, int> mapa;
    char mat[n][m];
    vector<string> rows;
    vector<string> cols(m);
    for (int j = 0; j < n; ++j) {
      string s;
      for (int k = 0; k < m; ++k) {
        cin >> mat[j][k];
        s.push_back(mat[j][k]);
        cols[k].push_back(mat[j][k]);
        mapa[mat[j][k]] ++;
      }
      rows.push_back(s);
    }

    int q;
    cin >> q;
    for (int j = 0; j < q; ++j) {
      string s;
      cin >> s;

      int ans = 0;
      if (s.size() > 1) {
        for (int k = 0; k < rows.size(); ++k) {
          ans += count(rows[k], s);
        }

        for (int k = 0; k < cols.size(); ++k) {
          ans += count(cols[k], s);
        }
      }
      else {
        ans += mapa[s[0]];
      }

      cout << ans << endl;
    }

  }

  return 0;
}