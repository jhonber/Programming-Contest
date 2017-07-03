// http://codeforces.com/contest/822/problem/B

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int a, b;
  string s, t;
  while (cin >> a >> b >> s >> t) {
    int best = 1e9;
    int ind = 0;
    for (int i = 0; i + s.size() <= t.size(); ++i) {
      int tot = 0;
      for (int j = 0; j < s.size(); ++j) {
        tot += s[j] != t[i + j];
      }

      if (best > tot) {
        ind = i;
        best = tot;
      }
    }

    vector<int> pos;
    for (int i = 0; i < s.size(); ++i) {
      if (t[i + ind] != s[i]) pos.push_back(i + 1);
    }

    cout << pos.size() << endl;
    for (int i = 0; i < pos.size(); ++i) cout << pos[i] << " "; cout << endl;
  }

  return 0;
}