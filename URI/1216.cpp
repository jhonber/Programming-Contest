#include<bits/stdc++.h>
using namespace std;

int main() {
  string s;
  double sum = 0;
  double tot = 0;

  while (cin >> s) {
    if (!isalpha(s[0])) {
      stringstream ss(s);
      double a;
      ss >> a;
      sum += a;
      tot ++;
    }
  }

  printf("%.1lf\n", sum / tot);
  return 0;
}