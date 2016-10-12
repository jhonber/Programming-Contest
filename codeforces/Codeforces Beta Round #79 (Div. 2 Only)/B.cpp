// http://codeforces.com/contest/102/problem/B

#include<bits/stdc++.h>
using namespace std;
#define D(x) cout << #x << " = " << (x) << endl;

void solve (string s, int &cnt) {
  if (s.size() == 1) return;

  int sum = 0;
  for (int i = 0; i < s.size(); ++i) {
    sum += s[i] - '0';
  }

  stringstream ss;
  ss << sum;
  string s2;
  ss >> s2;

  cnt ++;
  solve(s2, cnt);
}

int main() {
  string s;
  cin >> s;

  int ans = 0;
  solve(s, ans);
  cout << ans << endl;

  return 0;
}