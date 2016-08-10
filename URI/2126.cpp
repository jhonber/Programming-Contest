#include<bits/stdc++.h>
using namespace std;
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  string a, b;
  int t = 1;
  while (cin >> a >> b) {
    int ind = 0;
    int pos = 0;
    int cnt = 0;
    while (ind < b.size()) {
      ind = b.find(a, ind);
      if (ind == string::npos) break;
      pos = ind;

      ind += a.size();
      cnt ++;
    }

    cout << "Caso #" << t++ << ":" << endl;
    if (!cnt) {
      cout << "Nao existe subsequencia" << endl;
      cout << endl;
      continue;
    }

    cout << "Qtd.Subsequencias: " << cnt << endl;
    cout << "Pos: " << pos + 1 << endl;
    cout << endl;
  }

  return 0;
}