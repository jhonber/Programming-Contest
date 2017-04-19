// https://csacademy.com/contest/round-25/#task/suspect-interval
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;

  bool one = false;
  bool mmax = false;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
    if (v[i] == 1) one = true;
    if (v[i] == 1e5) mmax = true;
  }

  sort(v.begin(), v.end());

  if (v[0] == 1 && v[1] == 1e5) {
    cout << 99999 << endl;
    return 0;
  }

  v.push_back(1);
  v.push_back(1e5);
  sort(v.begin(), v.end());

  int ans = v[0];
  for (int i = 2; i < v.size(); ++i) {
    int tot = v[i] - (v[i - 2] + 1);
    if (v[i - 2] == 1 && !one) tot ++;
    if (v[i] == 1e5 && !mmax) tot ++;
    ans = max(ans, tot);
  }


  cout << ans << endl;
  return 0;
}
