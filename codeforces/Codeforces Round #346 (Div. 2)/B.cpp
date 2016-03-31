// http://codeforces.com/contest/659/problem/B

#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n, m;
  cin >> n >> m;

  string name;
  int r, s;
  map<int, vector<pair<int, string>>> mapa;
  for (int i = 0; i < n; ++i) {
    cin >> name >> r >> s;
    mapa[r].push_back({s, name});
  }

  for (auto i : mapa) {
    vector<pair<int, string>> cur = i.second;
    sort(cur.begin(), cur.end());
    reverse(cur.begin(), cur.end());

    if (cur.size() > 2) {
      if (cur[1].first == cur[2].first) cout << "?" << endl;
      else cout << cur[0].second << " " << cur[1].second << endl;
    }
    else {
      cout << cur[0].second << " " << cur[1].second << endl;
    }
  }

  return 0;
}