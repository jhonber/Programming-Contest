// http://codeforces.com/contest/651/problem/B

#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  cin >> n;

  map<int, int> mapa;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    mapa[a] ++;
  }

  vector<int> v;
  while (true) {
    int f = false;
    for (auto &i : mapa) {
      if (i.second > 0) {
        v.push_back(i.first);
        i.second --;
        f = true;
      }
    }
    if (!f) break;
  }

  int ans = 0;
  for (int i = 1; i < n; ++i) {
    if (v[i] > v[i - 1]) ans ++;
  }

  cout << ans;

  return 0;
}