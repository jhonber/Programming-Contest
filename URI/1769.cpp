#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  vector<int> v(11, 0);
  int num1, num2, num3, num4;
  while (scanf("%d.%d.%d-%d", &num1, &num2, &num3, &num4) == 4) {

    for (int i = 0; i < 11; ++i) v[i] = 0;
    int ind = 2;
    while (num1 > 0) {
      v[ind] = num1 % 10;
      num1 /= 10;
      ind --;
    }

    ind = 5;
    while (num2 > 0) {
      v[ind] = num2 % 10;
      num2 /= 10;
      ind --;
    }

    ind = 8;
    while (num3 > 0) {
      v[ind] = num3 % 10;
      num3 /= 10;
      ind --;
    }

    v[9] = num4 / 10;
    v[10] = num4 % 10;

    int a = 0;
    int b = 0;

    for (int i = 0; i < 9; ++i) {
      a += v[i] * (i + 1);
    }

    int cnt = 9;
    for (int i = 0; i < 9; ++i) {
      b += v[i] * cnt;
      cnt --;
    }

    a %= 11;
    if (a == 10) a = 0;

    b %= 11;
    if (b == 10) b = 0;

    if (a == v[9] && b == v[10]) cout << "CPF valido" << endl;
    else cout << "CPF invalido" << endl;
  }

  return 0;
}