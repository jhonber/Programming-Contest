#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];

  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());

  int tot = accumulate(v.begin(), v.end(), 0);

  for (int i = 2; i < n; i += 3) tot -= v[i];
  cout << tot << endl;

  return 0;
}
