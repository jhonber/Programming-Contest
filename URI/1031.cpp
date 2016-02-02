#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  while (cin >> n) {
    if (!n) break;

    for (int i = 1; i <= 1000; ++i) {
      vector<int> v(n, 0);
      v[0] = true;
      int cnt = 0;
      int last = 0;
      int tot = n-1;
      int ind = 0;
      while (tot > 0) {
        ind %= n;
        if (!v[ind]) cnt ++;
        if (cnt == i) {
          v[ind] = true;
          last = ind + 1;
          cnt = 0;
          tot --;
        }
        ind ++;
      }

      if (last == 13) {
        cout << i << endl;
        break;
      }
    }
  }

  return 0;
}