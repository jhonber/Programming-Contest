#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  while (cin >> n) {
    map<int, int> a, b;
    while (n --> 0) {
      int i;
      char t;
      cin >> i >> t;

      if (t == 'D') a[i] ++;
      else b[i] ++;
    }

    int ans = 0;
    for (auto i: a) {
      while (i.second > 0) {
        int cur = i.first;
        if (b.count(cur) > 0) {
          ans ++;
          b[cur] --;
          if (b[cur] == 0) b.erase(cur);
          i.second --;
        }
        else break;
      }
    }
    cout << ans << endl;
  }

  return 0;
}