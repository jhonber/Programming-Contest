#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;
#define endl '\n'

int main() {
  int n;
  while (cin >> n) {
    if (n == -1) break;

    vector<string> v(n + 10);
    for (int i = 0; i + 1 < n; ++i) {
      string s;
      cin >> s;
      reverse(s.begin(), s.end());
      v[i + 2] = s;
    }


    int ind = 2;
    while (true) {
      while (v[ind].size() > 0) {
        int next = 1;
        while (next == 1) {
          if (v[ind].size() == 0) break;
          next = v[ind].back() - '0'; v[ind].pop_back();
          if (next == 1) {
            cout << ind;
          }
        }

        ind = next;
      }

      int found = false;
      for (int i = 2; i <= n; ++i) {
        if (v[i].size() > 0) {
          ind = i;
          found = true;
          break;
        }
      }

      if (!found) break;
    }

    cout << endl;
  }

  return 0;
}