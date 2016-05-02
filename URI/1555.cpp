#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int t;
  cin >> t;

  int x, y;
  while (t --> 0) {
    cin >> x >> y;

    vector<pair<int, int>> v(3);
    v[0] = {(3 * x) * (3 * x) + (y * y), 0};
    v[1] = {2 * (x * x) + (5 * y) * (5 * y), 1};
    v[2] = {-100 * x + (y * y * y), 2};

    map<int, string> ans;
    ans[0] = "Rafael";
    ans[1] = "Beto";
    ans[2] = "Carlos";
    sort(v.begin(), v.end());

    cout << ans[v[2].second] << " ganhou" << endl;
  }

  return 0;
}