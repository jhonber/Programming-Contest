#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  while (cin >> n) {
    if (!n) break;

    vector<string> Q;
    Q.push_back("FACE");

    int ans = 0;
    string cur = "FACE";
    for (int i = 0; i < n; ++i) {
      cin >> cur[0] >> cur[1] >> cur[2] >> cur[3];

      string tmp = cur;;
      reverse(tmp.begin(), tmp.end());

      if (tmp == Q.back()) {
        Q.pop_back();
        if (Q.empty()) Q.push_back("FACE");
        ans ++;
      }
      else {
        Q.push_back(cur);
      }
    }

    cout << ans << endl;
  }
  return 0;
}