// http://codeforces.com/contest/767/problem/A

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  cin >> n;

  int mmax = n;
  vector<bool> mark(n + 1, 0);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    mark[x] = true;
    if (x == mmax) {
      while (x >= 1 && mark[x]) {
        cout << x << " ";
        x --;
      }
      cout << endl;

      mmax = x;
    }
    else cout << endl;
  }

  return 0;
}