#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n = 12;

  double mat[n][n];
  char op;
  cin >> op;

  for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> mat[i][j];

  int x = n - 2;
  double sum = 0;
  double tot = 0;
  for (int j = 0; j < n / 2; ++j) {
    for (int i = j + 1; i <= x ; ++i) {
      sum += mat[j][i];
      tot ++;
    }
    x --;
  }

  if (op == 'S') printf("%.1lf\n", sum);
  else printf("%.1lf\n", sum / tot);


  return 0;
}