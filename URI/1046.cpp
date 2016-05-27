#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int a, b;
  cin >> a >> b;

  vector<int> v(24);
  for (int i = 0; i < 24; ++i) {
    v[i] = i;
  }

  int ans = 1;
  int ind = a;
  ind ++;
  while (v[ind % 24] != b) {
    ind ++;
    ans ++;
  }

  cout << "O JOGO DUROU " << ans << " HORA(S)" << endl;
  return 0;
}