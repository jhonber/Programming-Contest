// http://codeforces.com/contest/797/problem/C

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() { IO
  string s;
  while (cin >> s) {
    string left;

    set<char> letters;
    for (int i = 0; i < s.size(); ++i) letters.insert(s[i]);

    int ind = 0;
    while (ind < s.size()) {
      char found;
      int next;
      for (auto j: letters) {
        char cur = j;
        int pos = s.find(cur, ind);
        if (pos != string::npos) {
          found = cur;
          next = pos;
          break;
        }
      }

      while (left.size() > 0 && left.back() <= found) {
        cout << left.back();
        left.pop_back();
      }

      for (int i = ind; i < next; ++i) left.push_back(s[i]);

      while (left.size() > 0 && left.back() <= found) {
        cout << left.back();
        left.pop_back();
      }

      cout << found;
      ind = next + 1;
    }

    while (left.size() > 0) {
      cout << left.back();
      left.pop_back();
    }

    cout << endl;
  }

  return 0;
}