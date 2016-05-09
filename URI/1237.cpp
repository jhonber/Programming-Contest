#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'

int main() {
  string a, b;
  while (getline(cin, a)) {
    getline(cin, b);

    int s1 = a.size();
    int s2 = b.size();

    if (s1 < s2) {
      swap(a, b);
      swap(s1, s2);
    }

    int ans = 0;
    int mx = min(s1, s2);

    for (int i = 0; i < a.size(); ++i) {
      for (int j = 0; j < b.size(); ++j) {
        if (a[i] == b[j]) {
          int ii = i;
          int jj = j;

          int tot = 0;
          while (ii < a.size() && jj < b.size() && a[ii] == b[jj]) {
            ii ++;
            jj ++;
            tot ++;
          }
          tot = max(tot, 1);
          ans = max(tot, ans);
        }
      }
    }

    cout << ans << endl;
  }

  return 0;
}