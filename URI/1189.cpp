#include<bits/stdc++.h>
using namespace std;

int main() {
  char c;
  cin >> c;

  int cnt = -1;
  int n = 12;
  double sum = 0;
  int f = true;
  int tot = 0;
  for (int i = 0; i < n; ++i) {
    if (f) cnt ++;
    else cnt --;

    if (cnt == 6) {
      cnt = 5;
      f = false;
    }

    for (int j = 0; j < n; ++j) {
      double a;
      cin >> a;


      if (i > 0 && i < 11 && j < cnt) {
        tot ++;
        sum += a;
      }
    }
  }

  if (c == 'S') printf("%.1lf\n", sum);
  else printf("%.1lf\n", sum / tot);

  return 0;
}