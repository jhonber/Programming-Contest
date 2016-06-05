#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " < (x) << endl;

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    int cur = i + 1;
    cout << cur;
    for (int j = 0; j < 2; ++j) {
      cur *= (i + 1);
      cout << " " << cur;
    }
    cout << endl;
  }

  return 0;
}