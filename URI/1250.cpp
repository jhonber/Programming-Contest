#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int t;
  cin >> t;

  while (t --> 0) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
      cin >> v[i];
    }

    string s;
    cin >> s;

    int ans = 0;
    for (int i = 0; i < n; ++i) {
      if ((s[i] =='J' && v[i] > 2) || (s[i] =='S' && v[i] <= 2))
        ans ++;
    }

    cout << ans << endl;
  }

  return 0;
}