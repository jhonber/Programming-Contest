#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  long long a;

  while (cin >> n) {
    if (!n) break;

    map<long long, int> mapa;
    for (int i = 0; i < n; ++i) {
      cin >> a;
      mapa[a] ++;
    }

    for (auto i: mapa) {
      if (i.second % 2 == 1) {
        cout << i.first << endl;
        break;
      }
    }
  }

  return 0;
}