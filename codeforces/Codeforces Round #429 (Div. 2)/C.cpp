// http://codeforces.com/contest/841/problem/C

#include<bits/stdc++.h>

using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
  int n;
  while (cin >> n) {
    vector<int> v(n), v2(n), v3;
    for (int i = 0; i < n; ++i) cin >> v[i];
    for (int i = 0; i < n; ++i) cin >> v2[i];

    v3 = v2;
    sort(v.begin(), v.end());
    sort(v2.begin(), v2.end());
    reverse(v2.begin(), v2.end());

    map<int, vector<int>> mapa;
    for (int i = 0; i < n; ++i) {
      mapa[v2[i]].push_back(v[i]);
    }

    for (int i = 0; i < n; ++i) {
      int x = mapa[v3[i]].back();
      mapa[v3[i]].pop_back();
      cout << x << " ";
    }
    cout << endl;
  }

  return 0;
}