#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  cin >> n;

  int v[] = {2, 3, 4, 5};
  int ans[] = {0, 0, 0, 0};
  while (n --> 0) {
    int a;
    cin >> a;

    for (int i = 0; i < 4; ++i) if (a % v[i] == 0) ans[i] ++;
  }

  for (int i = 0; i < 4; ++i) {
    cout << ans[i] << " Multiplo(s) de " << v[i] << endl;
  }

  return 0;
}