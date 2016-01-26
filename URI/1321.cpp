#include<bits/stdc++.h>
using namespace std;
 
int main() {
  while (true) {
    vector<int> v(3);
    vector<int> v2(3);
    int tot = 0;
    set<int> ready;
    for (int i = 0; i < 3; ++i) {
      cin >> v[i];
      ready.insert(v[i]);
    }
    for (int i = 1; i < 3; ++i) {
      cin >> v2[i];
      ready.insert(v2[i]);
    }
 
    int found = false;
    if (v[0] + v[1] + v[2] + v2[1] + v2[2] == 0) break;
    for (int i = 1; i <= 52; ++i) {
      if (ready.count(i) != 0) continue;
      vector<int> vv = v2;
      vv[0] = i;
      sort(vv.begin(), vv.end());
 
      int bads = 0;
      do {
        int cnt = 0;
        for (int j = 0; j < 3; ++j) {
          if (vv[j] < v[j]) cnt ++;
        }
        if (cnt >= 2) bads ++;
      } while (next_permutation(vv.begin(), vv.end()));
 
      if (!bads) {
        cout << i << endl;
        found = true;
        break;
      }
    }
    if (!found) cout << -1 << endl;
  }
 
  return 0;
}
