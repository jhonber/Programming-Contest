#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int l;
  cin >> l;

  char op;
  cin >> op;

  double mat[12][12];
  for (int i = 0; i < 12; ++i) {
    for (int j = 0; j < 12; ++j) {
      cin >> mat[i][j];
    }
  }

  double sum = 0;
  for (int i = 0; i < 12; ++i) {
    sum += mat[l][i];
  }

  if (op == 'S') cout << (int)sum << endl;
  else printf("%.1lf\n", (sum / 12.0));

  return 0;
}