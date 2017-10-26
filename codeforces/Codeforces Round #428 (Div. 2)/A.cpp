// http://codeforces.com/contest/839/problem/A

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
  int n, k;
  while (cin >> n >> k) {
    int cur = 0;
    int tot = 0;
    int ind = -1;
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      cur += x;

      if (cur - 8 >= 0) {
        tot += 8;
        cur -= 8;
      }
      else {
        tot += cur;
        cur = 0;
      }

      if (tot >= k) {
        if (ind == -1) ind = i + 1;
      }
    }

    cout << ind << endl;
  }

  return 0;
}