#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  while (cin >> n) {
    if (!n) break;

    vector<int> v;
    for (int i = 0; i < n; ++i) {
      int a;
      cin >> a;
      v.push_back(a);
    }

    v.push_back(v[0]);
    v.push_back(v[1]);

    bool dir = 1;
    if (v[0] > v[1]) dir = 0;

    int ans = 0;
    for (int i = 2; i < v.size(); ++i) {
      int cur = 1;
      if (v[i - 1] > v[i]) cur = 0;
      if (cur != dir) ans ++;
      dir = cur;
    }

    cout << ans << endl;
  }

  return 0;
}