#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

unordered_map<int, bool> mapa;

void solve (int n) {
  if (n == 0) return;
  n %= 1000000;
  n /= 100;

  if (n > 0 && mapa[n] > 0) return;
  mapa[n] = true;
  solve(n * n);
}

int main() {
  int n;
  while (cin >> n) {
    if (!n) break;

    mapa[n] = true;
    solve(n * n);

    cout << mapa.size() << endl;
    mapa.clear();
  }

  return 0;
}