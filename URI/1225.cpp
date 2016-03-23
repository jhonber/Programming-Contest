#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  while (cin >> n) {
    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];

    int tot = accumulate(v.begin(), v.end(), 0);
    if (tot % n != 0) cout << -1 << endl;
    else {
      int med = tot / n;
      long long ans = 0;
      for (int i = 0; i < n; ++i) {
        ans += abs(v[i] - med);
      }
      cout << (ans / 2) + 1 << endl;
    }
  }

  return 0;
}