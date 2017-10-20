// http://codeforces.com/contest/873/problem/A

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main () {
  int n, k, x;
  while (cin >> n >> k >> x) {
    int tot = 0;
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      if (i + k < n)
        tot += x;
    }

    cout << tot + (k * x) << endl;
  }

  return 0;
}