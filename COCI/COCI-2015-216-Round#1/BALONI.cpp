#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  int ans = 0;
  map<int, int> mapa;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;

    if (mapa[a + 1] == 0) ans ++;
    else mapa[a + 1] --;
    mapa[a] ++;
  }

  cout << ans << endl;
  return 0;
}
