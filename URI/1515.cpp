#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  while (cin >> n) {
    if (!n) break;

    map<int, string> mapa;
    for (int i = 0; i < n; ++i) {
      string name;
      int a, b;
      cin >> name >> a >> b;

      int cur = a - b;
      mapa[cur] = name;
    }

    map<int, string> :: iterator it = mapa.begin();
    cout << it->second << endl;
  }

  return 0;
}