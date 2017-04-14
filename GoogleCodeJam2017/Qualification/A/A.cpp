#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

string solve (string s, int k) {
  int steps = 0;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == '-') {
      if (i + k <= s.size()) {
        for (int j = 0; j < k; ++j) {
          s[i + j] = (s[i + j] == '-' ? '+' : '-');
        }

        steps ++;
      }
      else {
        return "IMPOSSIBLE";
      }
    }
  }

  return to_string(steps);
}

int main() {
  int t, TC = 1;
  cin >> t;

  while (t --> 0) {
    string s;
    int k;
    cin >> s >> k;

    cout << "Case #" << TC ++ << ": " << solve(s, k) << endl;
  }

  return 0;
}
