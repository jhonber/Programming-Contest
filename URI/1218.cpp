#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  string n;
  string s;
  int tc = 1;
  while (getline(cin, s)) {
    n = s;
    getline(cin, s);

    int f = 0;
    int m = 0;

    int cnt = 0;
    stringstream ss;
    ss << s;
    string a, b;

    while (ss >> a) {
      ss >> b;

      if (a == n) {
        cnt ++;
        if (b == "F") f ++;
        else m ++;
      }
    }

    if (tc > 1) cout << endl;
    cout << "Caso " << tc ++ << ":" << endl;
    cout << "Pares Iguais: " << cnt << endl;
    cout << "F: " << f << endl;
    cout << "M: " << m << endl;
  }

  return 0;
}
