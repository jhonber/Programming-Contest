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

  double sum = 0;
  int tot = 0;
  int cnt = 11;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < cnt; ++j) {
      sum += mat[i][j];
      tot ++;
    }
    cnt --;
  }

  cout << fixed << setprecision(1);
  if (op == 'S') cout << sum << endl;
  else cout << sum / tot << endl;

  return 0;
}
