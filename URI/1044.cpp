#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " " << (x) << endl;

int main() {
  int a, b;
  cin >> a >> b;

  if (a > b) swap(a, b);

  int x = b / a;
  if (x * a == b) cout << "Sao Multiplos" << endl;
  else cout << "Nao sao Multiplos" << endl;

  return 0;
}