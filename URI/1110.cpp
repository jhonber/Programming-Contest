#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  while (cin >> n) {
    if (!n) break;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) v[i] = n - i;

    vector<int> ans;
    while (v.size() > 1) {
      ans.push_back(v.back());

      if (!v.empty())
        v.pop_back();

      v.insert(v.begin(), v.back());
      if (!v.empty())
        v.pop_back();
    }

    cout << "Discarded cards: " << ans[0];
    for (int i = 1; i < ans.size(); ++i) cout << ", " << ans[i]; cout << endl;
    cout << "Remaining card: " << v[0] << endl;
  }

  return 0;
}