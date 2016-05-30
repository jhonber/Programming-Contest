#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() { IO
  string a, b;
  int TC = 1;
  while (cin >> a >> b) {
    if (a == "0") break;

    if (TC > 1) cout << endl;
    cout << "Instancia " << TC ++ << endl;
    int good = false;
    if (b.find(a) != string::npos) good = true;
    cout << (good ? "verdadeira" : "falsa") << endl;
  }

  return 0;
}