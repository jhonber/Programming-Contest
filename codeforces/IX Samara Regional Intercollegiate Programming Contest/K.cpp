// http://codeforces.com/problemset/gymProblem/100971/K

#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

bool is_pal (string s) {
  int t = s.size() / 2;
  int j = s.size() - 1;
  for (int i = 0; i <= t; ++i, j --) {
    if (s[i] != s[j]) return false;
  }
  return true;
}

int main() {
  string s, s2, s3;
  cin >> s;

  if (is_pal(s)) {
    cout << "YES" << endl;
    cout << (s.size() / 2) + 1 << endl;
    return 0;
  }

  int t = s.size() / 2;
  int j = s.size() - 1;
  for (int i = 0; i <= t; ++i, j --) {
    if (s[i] != s[j]) {
      s2 = s3 = s;
      s2.erase(s2.begin() + i);
      s3.erase(s3.begin() + j);
      if (is_pal(s2)) {
        cout << "YES" << endl;
        cout << i + 1 << endl;
      }
      else if (is_pal(s3)){
        cout << "YES" << endl;
        cout << j + 1 << endl;
      }
      else {
        cout << "NO" << endl;
      }

      return 0;
    }
  }

  return 0;
}
