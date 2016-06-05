#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " < (x) << endl;

int main() {
  int n;
  cin >> n;

  double w [] = {2, 3, 5};
  for (int i = 0; i < n; ++i) {
    double sum = 0;
    for (int j = 0; j < 3; ++j) {
      double x;
      cin >> x;
      sum += x * w[j];
    }

    printf("%.1lf\n", sum / 10.0);
  }

  return 0;
}