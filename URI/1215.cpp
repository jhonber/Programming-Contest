#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

bool comp(string a, string b) {
  D(a[0] < b[0])
  return a + b < b + a;
}

int main() {
  string s;
  vector<string> ans[26];
  while (getline(cin, s)) {
    for (int i = 0; i < s.size(); ++i) {
      s[i] = tolower(s[i]);
      if (!isalpha(s[i])) s[i] = ' ';
    }

    stringstream ss;
    ss << s;

    string token;
    while (getline(ss, token, ' ')) {
      if (token.size() > 0) {
        ans[token[0] - 'a'].push_back(token);
      }
    }

  }

  for (int i = 0; i < 26; ++i) {
    sort(ans[i].begin(), ans[i].end());
    ans[i].erase(unique(ans[i].begin(), ans[i].end()), ans[i].end());
  }

  for (int i = 0; i < 26; ++i) {
    for (int j = 0; j < ans[i].size(); ++j) {
      cout << ans[i][j] << endl;
    }
  }

  return 0;
}