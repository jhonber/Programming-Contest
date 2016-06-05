#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " < (x) << endl;

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    int cur = i + 1;
    int v[3] = {};
    v[0] = cur;
    for (int j = 1; j < 3; ++j) {
      cur = cur * (i + 1);
      v[j] = cur;
    }

    cout << v[0] << " " << v[1] << " " << v[2] << endl;
    cout << v[0] << " " << v[1] + 1<< " " << v[2] + 1 << endl;
  }

  return 0;
}