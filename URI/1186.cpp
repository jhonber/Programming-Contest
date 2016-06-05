#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n = 12;

  char op;
  cin >> op;

  double mat[n][n];
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> mat[i][j];
    }
  }

  double sum, tot;
  sum = tot = 0;
  for (int i = 0; i < n; ++i) {
    for (int k = n - i; k < n; ++k) {
      tot ++;
      sum += mat[i][k];
    }
  }

  if (op == 'S') printf("%.1lf\n", sum);
  else printf("%.1lf\n", sum / tot);
  return 0;
}