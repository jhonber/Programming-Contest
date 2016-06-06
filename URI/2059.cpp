#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int a, b, c, d, e;
  cin >> a >> b >> c >> d >> e;

  int win = 1;
  int odd = (b + c) % 2;

  if (d) {
    if (e) win = 2;
  }
  else {
    if (a && odd || !a && !odd) {
      win = 2;
    }
  }

  cout << "Jogador " << win << " ganha!" << endl;
  return 0;
}