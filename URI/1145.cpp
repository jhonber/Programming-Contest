#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " < (x) << endl;

int main() {
  int n, m;
  cin >> n >> m;

  int cnt = 1;
  for (int i = 1; i <= m; ++i) {
    cout << i;
    if (cnt % n == 0) cout << endl;
    else cout << " ";
    cnt ++;
  }

  return 0;
}