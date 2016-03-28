#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  int tc = 1;
  while (cin >> n) {
    if (!n) break;

    int len = 0;
    vector<string> v(n);
    for (int i = 0; i < n; ++i) {
      cin >> v[i];
      len = max(len, (int)v[i].size());
    }

    if (tc > 1) cout << endl;
    for (int i = 0; i < n; ++i) {
      string s = v[i];
      while (s.size() < len) s = " " + s;
      cout << s << endl;
    }
    tc ++;
  }

  return 0;
}
