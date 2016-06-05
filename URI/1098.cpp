#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

bool check(double x) {
  return ceil(x) == floor(x);
}

void p(double x) {
  cout << x;
}

int main() {
  double i = 0;
  while (i <= 2) {
    for (int j = 1; j <= 3 && i <= 2; ++j) {
      cout << "I=";
      p(i);
      cout << " J=";
      p(i + j);
      cout << endl;
    }
    i += .2;
    for (int j = 1; j <= 3 && i <= 2; ++j) {
      cout << "I=";
      p(i);
      cout << " J=";
      p(i + j);
      cout << endl;
    }
    i += .2;
  }

  return 0;
}