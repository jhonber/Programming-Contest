#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " " << (x) << endl;

int main() {
  int a, b;
  while (cin >> a >> b) {
    if (a == b) break;
    if (a - b < 0) cout << "Crescente" << endl;
    else cout << "Decrescente" << endl;
  }
  return 0;
}