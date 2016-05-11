// http://codeforces.com/contest/660/problem/A

#include<bits/stdc++.h>
using namespace std;

#define io ios_base::sync_with_stdio(false); cin.tie(null);
#define endl '\n'
#define d(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  while (cin >> n) {
    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];

    vector<int> ans;
    ans.push_back(v[0]);

    for (int i = 1; i < n; ++i) {
      if (__gcd(v[i - 1], v[i]) != 1) {
        ans.push_back(1);
        ans.push_back(v[i]);
      }
      else ans.push_back(v[i]);
    }

    cout << ((int)ans.size() - n) << endl;
    for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
  }
  return 0;
}
