// https://csacademy.com/contest/round-25/#task/0-sum-array

#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;

  int tot = 0;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
    tot += v[i];
  }

  for (int i = 0; i < n; ++i) {
    if (tot - 2 * v[i] == 0) {
      cout << i + 1;
      return 0;
    }

  }

  cout << -1;

  return 0;
}
