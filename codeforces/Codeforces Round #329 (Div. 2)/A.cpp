// http://codeforces.com/contest/593/problem/A

#include<bits/stdc++.h>
using namespace std;
#define D(x) cout << #x << " = " << (x) << endl;
#define endl '\n'

pair<string, int> f (string s) {
  int size = s.size();
  vector<int> v(26, 0);
  for (int i = 0; i < size; ++i) v[s[i] - 'a'] ++;

  string sub;
  for (int i = 0; i < 26; ++i) if (v[i]) {
    sub.push_back(char(i + 'a'));
  }

  return make_pair(sub, size);
}

bool check(string a, string b) {
  if (a.size() < b.size()) return false;
  if (a.size() > b.size()) {
    if (b[0] == a[0] || b[0] == a[1]) return true;
    return false;
  }

  return a == b;
}

int main() {
  int n;
  cin >> n;

  vector< pair<string, int> > all(n);
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    all[i] = f (s);
  }

  vector<string> possibles;
  for (int i = 0; i < 26; ++i) {
    string sub;
    sub.push_back(char(i + 'a'));
    possibles.push_back(sub);
    for (int j = i + 1; j < 26; ++j) {
      if (i != j) {
        sub.push_back(char(j + 'a'));
        possibles.push_back(sub);
      }
      sub.pop_back();
    }
  }

  int ans = 0;
  for (int i = 0; i < possibles.size(); ++i) {
    int tmp = 0;
    for (int j = 0; j < n; ++j) {
      if ( check(possibles[i], all[j].first) ) {
        tmp += all[j].second;
      }
    }
    ans = max(ans, tmp);
  }

  cout << ans;
  return 0;
}