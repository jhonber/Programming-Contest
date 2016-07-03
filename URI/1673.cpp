#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

pair<int, char> process (string &s, char &cur) {
  int cnt = 1;
  while (s.size() > 0 && s.back() == cur) {
    s.pop_back();
    cnt ++;
    if (cnt == 9) return {cnt, cur};
  }

  return {cnt, cur};
}

int main() {
  string s;
  while (getline(cin, s)) {
    reverse(s.begin(), s.end());

    while (s.size() > 0) {
      char cur = s.back(); s.pop_back();
      pair<int, char> p = process(s, cur);

      if (p.first == 1) {
        cout << 1;
        if (p.second == '1') cout << 11;
        else cout << p.second;

        int f = false;
        while (s.size() > 0) {
          cur = s.back(); s.pop_back();
          p = process(s, cur);
          if (p.first != 1) {
            cout << 1;
            cout << p.first << p.second;
            f = true;
            break;
          }
          else {
            if (p.second == '1') cout << 11;
            else cout << p.second;
          }
        }

        if (!f) cout << 1;
      }
      else {
        cout << p.first << p.second;
      }
    }

    cout << endl;
  }

  return 0;
}