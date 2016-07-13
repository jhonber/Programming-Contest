// http://codeforces.com/contest/691/problem/B

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

string good = "AHIMOoTUVvWwXxY";

char mirror (char c) {
  if (c == 'd') return 'b';
  if (c == 'b') return 'd';
  if (c == 'p') return 'q';
  if (c == 'q') return 'p';

  for (int i = 0; i < good.size(); ++i) if (good[i] == c)
    return good[i];

  return '*';
}

int main() {
  string s;
  cin >> s;

  string ans = "TAK";
  int t = s.size();

  char mid = s[t / 2];
  int found = false;
  for (int i = 0; i < good.size(); ++i) if (good[i] == mid) {
    found = true;
    break;
  }

  if (t%2 != 0 && !found) {
    cout << "NIE";
    return 0;
  }

  for (int i = 0, j = t - 1; i < t / 2; ++i, --j) if (s[i] != mirror(s[j])) {
    ans = "NIE";
    break;
  }

  cout << ans;
  return 0;
}
