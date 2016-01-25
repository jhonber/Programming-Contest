#include<bits/stdc++.h>
using namespace std;

int main() {
  char op;
  cin >> op;

  vector<int> v = {0,1,2,3,4,5,5,4,3,2,1,0};
  int tot = 0;
  double sum = 0;
  for (int i = 0; i < 12; ++i) {
    for (int j = 0; j < 12; ++j) {
      double a;
      cin >> a;
      if (j >= 12 - v[i]) sum += a;
    }
    tot += v[i];
  }

  if (op == 'M') printf("%.1lf\n", sum / tot);
  else printf("%.1lf\n", sum);
  return 0;
}