// http://codeforces.com/contest/81/problem/A

#include<bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  cin >> s;

  int n = s.size();
  vector<int> Q;
  Q.push_back(0);

  for (int i = 1; i < n; ++i) {
    int last = Q.back();
    if (Q.size() > 0 && s[last] == s[i]) {
      Q.pop_back();
      s[last] = s[i] = '*';
    }
    else
      Q.push_back(i);
  }

  for (int i = 0; i < n; ++i) if (s[i] != '*') cout << s[i];
  return 0;
}