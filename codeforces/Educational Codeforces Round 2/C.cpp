// http://codeforces.com/contest/600/problem/C

#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(NULL); cin.tie(false);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  string s;
  cin >> s;

  vector<int> v(26, 0);
  for (int i = 0; i < s.size(); ++i) v[s[i] - 'a'] ++;

  int cnt = s.size();
  string ans;
  char mid;

  while (cnt > 0) {
    if (cnt == 1) {
      for (int i = 0; i < 26; ++i) if (v[i] > 0) {
        mid = i + 'a';
        break;
      }
      cnt --;
    }

    bool found = false;
    for (int i = 0; i < 26; ++i) if (v[i] >= 2) {
      found = true;
      v[i] -= 2;
      cnt -= 2;
      ans.push_back(char(i + 'a'));
    }

    if (!found && cnt > 1) {
      char a;
      for (int i = 0; i < 26; ++i) if (v[i] > 0) {
        a = i + 'a';
        v[i] --;
        break;
      }

      for (int i = 25; i >= 0; i--) if (v[i] > 0) {
        v[i] --;
        break;
      }

      cnt -= 2;
      ans.push_back(a);
    }
  }

  sort(ans.begin(), ans.end());
  cout << ans;
  reverse(ans.begin(), ans.end());
  if ((int)s.size() % 2 != 0) cout << mid;
  cout << ans;

  return 0;
}