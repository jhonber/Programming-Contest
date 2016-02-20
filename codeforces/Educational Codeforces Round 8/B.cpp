// http://codeforces.com/contest/628/problem/B

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;
#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);

int toInt(string s) {
  stringstream ss;
  ss << s;

  int n;
  ss >> n;
  return n;
}

int main() {
  string s;
  cin >> s;

  long long ans = 0;
  for (int i = 0; i + 1 < s.size(); ++i) {
    int c = (s[i]- '0');
    if (c % 4 == 0) ans ++;

    int num = toInt(s.substr(i, 2));
    if (num % 4 == 0) {
      ans += i + 1;
    }
  }

  int c = (s[s.size() - 1] - '0');
  if (c % 4 == 0) ans ++;


  cout << ans;
  return 0;
}