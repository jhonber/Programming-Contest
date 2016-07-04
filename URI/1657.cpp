#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;
#define IO ios::sync_with_stdio(false); cin.tie(NULL);

vector<string> gen (string s) {
  vector<string> all;
  string s2 = s;
  for (int i = 1; i < s.size(); ++i) {
    swap(s2[i], s2[i - 1]);
    all.push_back(s2);
    s2 = s;
  }

  s2 = s;
  for (int i = 0; i < s.size(); ++i) {
    s2.erase(s2.begin() + i);
    all.push_back(s2);
    s2 = s;
  }

  s2 = s;
  for (int i = 0; i <= s.size(); ++i) {
    for (int j = 0; j < 26; ++j) {
      s2.insert(s2.begin() + i, char(j + 'a'));
      all.push_back(s2);
      s2 = s;
    }
  }

  s2 = s;
  for (int i = 0; i < s.size(); ++i) {
    for (int j = 0; j < 26; ++j) {
      s2[i] = char(j + 'a');
      all.push_back(s2);
      s2 = s;
    }
  }

  return all;
}

int main() { IO
  int n;
  cin >> n;

  unordered_map<string, bool> hash;
  unordered_map<string, int> ord;
  string s;
  for (int i = 0; i < n; ++i) {
    cin >> s;

    hash[s] = true;
    ord[s] = i;
  }

  int k;
  cin >> k;

  while (k --> 0) {
    cin >> s;

    if (hash[s]) {
      cout << s << " is correct" << endl;
      continue;
    }

    vector<string> all = gen(s);
    int found = false;
    int mm = INT_MAX;
    string missing;

    for (int i = 0; i < all.size(); ++i) {
      if (hash[all[i]]) {
        found = true;
        if (ord[all[i]] < mm) {
          mm = ord[all[i]];
          missing = all[i];
        }
      }
    }

    if (!found) cout << s << " is unknown" << endl;
    else cout << s << " is a misspelling of " << missing << endl;
  }

  return 0;
}