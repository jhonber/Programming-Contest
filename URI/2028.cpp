#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() { IO
  int n;
  int TC = 1;

  while (cin >> n) {
    vector<int> ans;
    for (int i = 0; i <= n; ++i) {
      if (i == 0) ans.push_back(0);
      for (int j = 0; j < i; ++j) {
        ans.push_back(i);
      }
    }

    cout << "Caso " << TC++ << ": " << ans.size() << " numero" << (n ? "s" : "") << endl;
    cout << ans[0];
    for (int i = 1; i < ans.size(); ++i) cout << " " << ans[i];
    cout << endl;
    cout << endl;
  }

  return 0;
}