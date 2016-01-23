// http://codeforces.com/contest/617/problem/B

#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define D(x) cout << #x << " = " << endl;

int main() {
  int n;
  cin >> n;

  int ones = 0;
  string s;
  for (int i = 0; i < n; ++i) {
    char c;
    cin >> c;
    s.push_back(c);
    if (c == '1') ones ++;
  }

  if (ones == 0) {
    cout << 0;
    return 0;
  }

  if (ones == 1) {
    cout << 1;
    return 0;
  }

  reverse(s.begin(), s.end());
  while (s.back() == '0') {
    s.pop_back();
  }

  reverse(s.begin(), s.end());
  while (s.back() == '0') {
    s.pop_back();
  }

  long long ans = 1;
  while (ones > 1) {
    if (s.find('1') != string::npos) {
      long long size = s.find('1');
      ans *= (size + 1);
      s = s.substr(size + 1);
      ones --;
    }
  }

  ans *= (int) s.size();

  cout << ans;
  return 0;
}