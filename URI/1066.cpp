#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int a;
  vector<int> v(4);
  for (int i = 0; i < 5; ++i) {
    cin >> a;
    if (a % 2 == 0) v[0] ++;
    else v[1] ++;

    if (a > 0) v[2] ++;
    else if (a < 0) v[3] ++;
  }


  cout << v[0] << " valor(es) par(es)" << endl;
  cout << v[1] << " valor(es) impar(es)" << endl;
  cout << v[2] << " valor(es) positivo(s)" << endl;
  cout << v[3] << " valor(es) negativo(s)" << endl;

  return 0;
}