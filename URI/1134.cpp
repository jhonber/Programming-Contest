#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " < (x) << endl;

int main() {
  int v[] = {1, 2, 3};
  int ans[] = {0, 0, 0};

  while (true) {
    int x;
    cin >> x;


    if (x >= 1 && x < 4) {
      ans[x - 1] ++;
    }

    if (x == 4) break;
  }

  cout << "MUITO OBRIGADO" << endl;
  cout << "Alcool: " << ans[0] << endl;
  cout << "Gasolina: " << ans[1] << endl;
  cout << "Diesel: " << ans[2] << endl;

  return 0;
}