#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() { IO
  int TC;
  cin >> TC;

  string s, t;
  int q;
  while (TC --> 0) {
    cin >> s;

    set<string> good;
    set<string> bad;
    cin >> q;
    for (int j = 0; j < q; ++j) {
      cin >> t;
      int ans = false;
      if (good.count(t) > 0) {
        cout << "y";
      }
      else if (bad.count(t) > 0) {
        cout << "n";
      }
      else if (s.find(t) != string::npos) {
        cout << "y";
        good.insert(t);
      }
      else {
        cout << "n";
        bad.insert(t);
      }
      cout << endl;
    }
  }

  return 0;
}
