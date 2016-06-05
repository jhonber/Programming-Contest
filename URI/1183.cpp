#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " < (x) << endl;

int main() {
  char op;
  cin >> op;

  int n = 12;
  double mat[n][n];

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> mat[i][j];
    }
  }

  double sum = 0;
  double tot = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      sum += mat[i][j];
      tot ++;
    }
  }

  if (op == 'S') printf("%.1lf\n", sum);
  else printf("%.1lf\n", sum / tot);

  return 0;
}