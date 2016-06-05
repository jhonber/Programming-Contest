#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " < (x) << endl;

int main() {
  int n = 6;

  double sum = 0;
  int pos = 0;
  for (int i = 0; i < n; ++i) {
    double a;
    cin >> a;

    if (a > 0) {
      pos ++;
      sum += a;
    }
  }

  cout << pos << " valores positivos" << endl;
  printf("%.1lf\n", sum / pos);

  return 0;
}