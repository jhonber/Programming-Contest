#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main () {
  string v, s;

  while (getline(cin, v)) {
    if (v.size() == 0) break;
    getline(cin, s);
    int cnt = 0;
    for (int i = 0; i < s.size(); ++i) {
      for (int j = 0; j < v.size(); ++j) {
        if (tolower(v[j]) == tolower(s[i])) {
          cnt ++;
          break;
        }
      }
    }

    cout << cnt << endl;
  }

  return 0;
}