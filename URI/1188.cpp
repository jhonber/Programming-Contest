#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

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

  double tot = 0;
  double sum = 0;
  int col = 5;
  int cnt = 2;
  for (int i = 7; i < n; ++i) {
    for (int j = col, k = 0; k < cnt; ++j, ++k) {
      sum += mat[i][j];
      tot ++;
    }

    col --;
    cnt += 2;
  }

  if (op == 'S') printf("%.1lf\n", sum);
  else printf("%.2lf\n", sum / tot);

  return 0;
}