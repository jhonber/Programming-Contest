#include<bits/stdc++.h>
using namespace std;

bool good(double x) {
  return x >= 0.0 && x <= 10.0;
}

int main() {
  double x;
  int cnt = 0;
  double sum = 0;
  while (cin >> x) {
    if (!good(x)) {
      cout << "nota invalida" << endl;
    }
    else {
      cnt ++;
      sum += x;
    }
    if (cnt == 2) {
      printf("media = %.2lf\n", sum / 2.0);
      sum = cnt = 0;
    }
  }

  return 0;
}
