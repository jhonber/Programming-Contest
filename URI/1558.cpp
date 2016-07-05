#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;

  while (cin >> n) {
    int found = false;
    for (int i = 0; i * i <= n && !found; ++i) {
      for (int j = 0; j * j <= n; ++j) {
        if (i * i + j * j == n) {
            cout << "YES" << endl;
            found = true;
            break;
        }
      }
    }

    if (!found) cout << "NO" << endl;
  }

  return 0;
}