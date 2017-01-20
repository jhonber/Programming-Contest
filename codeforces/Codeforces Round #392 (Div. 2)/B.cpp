// http://codeforces.com/contest/758/problem/B

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  string s;
  cin >> s;

  int n = s.size();
  int ok = true;
  vector<int> visited(n, 0);
  map<char, int> ans;
  while (ok) {
    for (int i = 0; i < n; ++i) {
      if (!visited[i] && s[i] != '!') {
        visited[i] = true;
        for (int j = i; j < n; j += 4) {
          if (!visited[j] && s[j] == '!') {
            ans[s[i]] ++;
            visited[j] = true;
            s[j] = s[i];
          }
        }

        for (int j = i; j >= 0; j -= 4) {
          if (!visited[j] && s[j] == '!') {
            ans[s[i]] ++;
            visited[j] = true;
            s[j] = s[i];
          }
        }

        ok = true;
        break;
      }
      ok = false;
    }
  }

  cout << ans['R'] << " " << ans['B'] << " " << ans['Y'] << " " << ans['G'] << endl;

  return 0;
}