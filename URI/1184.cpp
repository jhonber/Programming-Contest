#include<bits/stdc++.h>
using namespace std;
 
int main() {
  char op;
  cin >> op;
  double sum = 0;
  for (int i = 0; i < 12; ++i) {
    int x = i;
    for (int j = 0; j < 12; ++j) {
      double a;
      cin >> a;
      if (x > 0) sum += a;
      x --;
    }
  }
 
  if (op == 'S') printf("%.1lf\n", sum);
  else printf("%.1lf\n", sum / 66.);
 
  return 0;
}
