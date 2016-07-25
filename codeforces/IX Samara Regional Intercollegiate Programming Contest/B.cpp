// http://codeforces.com/problemset/gymProblem/100971/B

#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  cin >> n;

  vector<int> ans;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;

    if (x == i + 1) ans.push_back(x);
  }

  if (ans.size() == 0) {
    cout << 0 << endl;
    return 0;
  }

  if (ans.size() == 1) {
    cout << 1 << endl;
    cout << ans[0] << " ";
    for (int i = 0; i < n; ++i) if (i + 1 != ans[0]) {
      cout << i + 1 << endl;
      break;
    }
    return 0;
  }

  int f = false;
  if (ans.size() % 2 != 0) f = true;

  cout << (ans.size() / 2) + f << endl;
  for (int i = 0; i + 1 < ans.size(); i += 2) cout << ans[i] << " " << ans[i + 1] << endl;
  if (f) {
    int last = ans.back(); ans.pop_back();
    cout << last << " " << ans.back() << endl;
  }

  return 0;
}
