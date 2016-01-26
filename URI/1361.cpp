#include<bits/stdc++.h>
using namespace std;
 
int main() {
  int n,T;
  cin >> T;
  for (int x = 0; x < T; ++x) {
    cin >> n;
    vector<int> neg;
    vector<int> pos;
    for (int i = 0; i < n; ++i) {
      int a;
      cin >> a;
      if (a < 0) neg.push_back(abs(a));
      else pos.push_back(a);
    }
 
    sort(neg.begin(), neg.end());
    sort(pos.begin(), pos.end());
 
    int ans = 0;
    int bef = -1;
    for (int i = 0; i < neg.size(); ++i) {
      if (neg[i] < bef) continue;
      auto it = lower_bound(pos.begin(), pos.end(), neg[i] + 1);
      if (it != pos.end()) {
        ans += 2;
        bef = *it;
      }
      else {
        ans ++;
        break;
      }
    }
 
    int ans2 = 0;
    int bef2 = -1;
    for (int i = 0; i < pos.size(); ++i) {
      if (pos[i] < bef2) continue;
      auto it = lower_bound(neg.begin(), neg.end(), pos[i] + 1);
      if (it != neg.end()) {
        ans2 += 2;
        bef2 = *it;
      }
      else {
        ans2 ++;
        break;
      }
    }
    cout << max(ans, ans2) << endl;
  }
 
  return 0;
}
