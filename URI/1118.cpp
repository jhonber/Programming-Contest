#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

bool valid (double x) {
  if (x >= 0.0 && x <= 10.0) return true;
  return false;
}

int main() {
  double x;
  int cnt = 0;
  double sum = 0;
  while (cin >> x) {
    if (valid(x)) {
      sum += x;
      cnt ++;
    }
    else {
      cout << "nota invalida" << endl;
    }

    if (cnt == 2) {
      printf("media = %.2lf\n", sum / 2.0);
      cout << "novo calculo (1-sim 2-nao)" << endl;
      sum = 0.0;
      cnt = 0;

      int f = false;
      while (cin >> x) {
        if (x == 1.0) break;

        if (x == 2.0) {
          f = true;
          break;
        }

        cout << "novo calculo (1-sim 2-nao)" << endl;
      }

      if (f) break;
    }
  }

  return 0;
}