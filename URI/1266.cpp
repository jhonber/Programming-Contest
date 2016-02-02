#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  while (cin >> n) {
    if (!n) break;

    string s;
    for (int i = 0; i < n; ++i) {
      char c;
      cin >> c;
      s.push_back(c);
    }

    long long ans = 0;
    if (s.find('1') != string::npos) {
      int ind = s.find('1');
      ind ++;
      for (int i = 0; i < n; ++i) {
        int cnt = 0;
        while (i < n && s[(i + ind) % n] == '0') {
          cnt ++;
          i ++;
        }
        ans += cnt / 2;
      }
    }
    else ans += ceil(n / 2.0);
    cout << ans << endl;
  }

  return 0;
}
