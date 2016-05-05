#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int t;
  cin >> t;

  while (t --> 0) {
    int n;
    cin >> n;

    int ans = 0;
    string s;
    for (int i = 0; i < n; ++i) {
      cin >> s;
      for (int j = 0; j < s.size(); ++j) {
        ans += i + j + (s[j] - 'A');
      }
    }

    cout << ans << endl;
  }

  return 0;
}