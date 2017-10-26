#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
  int n;
  while (cin >> n) {
    vector<string> v(n);
    map<char, int> frec;
    for (int i = 0; i < n; ++i) {
      cin >> v[i];
      frec[v[i][0]] ++;
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
      string cur = v[i];
      map<char, int> cnt;

      frec[cur[0]] --;
      for (int j = 0; j < cur.size(); ++j) {
        cnt[cur[j]] ++;
      }

      bool ok = true;
      for (auto j: cnt) {
        if (frec[j.first] < j.second) ok = false;
      }

      frec[cur[0]] ++;
      ans += ok;

    }

    cout << ans << endl;
  }

  return 0;
}
