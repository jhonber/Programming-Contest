#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  double n;
  double sum = 0;
  double tot = 0;
  while (cin >> n) {
    if (n < 0) break;
    sum += n;
    tot ++;
  }

  printf("%.2lf\n", (sum / tot));
  return 0;
}