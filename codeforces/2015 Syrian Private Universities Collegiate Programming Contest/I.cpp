#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int t;
  cin >> t;

  while (t --> 0) {
    string s;
    cin >> s;

    vector<int> l(26, 0);
    for (int i = 0; i < s.size(); ++i) l[s[i] - 'a'] ++;


    int paila = false;
    string r = s;
    for (int i = 0, j = s.size() - 1; i < s.size() / 2; ++i, --j) {
      int f = false;
      for (int k = 0; k < 26; ++k) {
        if (l[k] >= 2) {
          l[k] -= 2;
          r[i] = r[j] = char(k + 'a');
          f = true;
          break;
        }
      }

      if (!f) {
        paila = true;
        break;
      }
    }

    if (!paila && s.size() % 2 != 0) {
      for (int i = 0; i < 26; ++i) if (l[i] > 0) {
        l[i] --;
        r[s.size() / 2] = char(i + 'a');
      }
    }

    int rest = accumulate(l.begin(), l.end(), 0);
    if (rest > 1) paila = true;

    cout << (paila ? "impossible": r) << endl;
  }

  return 0;
}
