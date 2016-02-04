#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  char c;
  cin >> c;

  double sum = 0;
  for (int i = 0; i < 12; ++i) {
    for (int j = 0; j < 12; ++j) {
      double a;
      cin >> a;
      if (j == n) sum += a;
    }
  }

  if (c == 'S') cout << sum << endl;
  else printf("%.1lf\n", sum / 12);
}
