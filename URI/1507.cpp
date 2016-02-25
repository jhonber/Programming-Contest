#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int t;
  cin >> t;

  while (t --> 0) {
    string s;
    cin >> s;

    vector<int> pos[222];
    for (int i = 0; i < s.size(); ++i) {
      pos[(int)s[i]].push_back(i);
    }

    int q;
    cin >> q;

    string s2;
    for (int i = 0; i < q; ++i) {
      cin >> s2;

      int last = 0;
      int paila = false;

      for (int j = 0; j < s2.size(); ++j) {
        int x = s2[j];
        auto it = lower_bound(pos[x].begin(), pos[x].end(), last);
        if(it == pos[x].end()){
            paila = true;
            break;
        }
        int ind = it - pos[x].begin();
        if (j > pos[x][ind]) {
          paila = true;
          break;
        }
        last = pos[x][ind] + 1;
      }

      if (!paila) cout << "Yes" << endl;
      else cout << "No" << endl;
    }

  }

  return 0;
}