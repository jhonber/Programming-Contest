// http://codeforces.com/contest/254/problem/C

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

void change (string &s, bool f = false) {
  for (int i = 0; i < s.size(); ++i) {
    if (!f) s[i] = tolower(s[i]);
    else s[i] = toupper(s[i]);
  }
}

bool check (string s, string t) {
  sort(s.begin(), s.end());
  sort(t.begin(), t.end());

  return s == t;
}

int main() {
#ifdef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  string s, t;
  while (cin >> s >> t) {
    change(s);
    change(t);

    int n = s.size();
    map<char, int> have, need, left;
    map<char, set<int>> right;

    for (int i = 0; i < n; ++i) {
      have[s[i]] ++;
      need[t[i]] ++;
      right[s[i]].insert(i);
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
      if (have[s[i]] > need[s[i]]) {
        for (int j = 0; j < 26; ++j) {
          char c = j + 'a';

          if (need[c] > have[c]) {
            char l = s[i];
            auto pos = right[l].lower_bound(i + 1);
            if (c > s[i] && pos != right[l].end()) break;

            have[s[i]] --;
            s[i] = c;
            have[c] ++;
            ans ++;
            break;
          }
        }

        if (!need[s[i]]) {
          for (int j = 0; j < 26; ++j) {
            char c = j + 'a';
            if (need[c] > have[c]) {
              have[s[i]] --;
              s[i] = c;
              have[c] ++;
              ans ++;
              break;
            }
          }
        }
      }
      right[s[i]].erase(i);
      left[s[i]] ++;

      if (left[s[i]] > need[s[i]]) {
        for (int j = 0; j < 26; ++j) {
          char c = j + 'a';
          if (need[c] > have[c]) {
            have[s[i]] --;
            s[i] = c;
            have[c] ++;
            ans ++;
            break;
          }
        }
      }

    }

    change(s, true);
    change(t, true);

    if (!check(s, t)) assert(false);
    cout << ans << endl << s << endl;
  }

  return 0;
}