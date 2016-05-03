#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int check(char c) {
  c = tolower(c);
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 's';
}

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;

    long long ans = 1;
    for (int j = 0; j < s.size(); ++j) {
      int tot = 2 + (check(s[j]));
      ans *= tot;
    }

    cout << ans << endl;
  }

  return 0;
}