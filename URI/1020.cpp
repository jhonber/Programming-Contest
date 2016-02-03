#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  int a = n / 365;
  n -= a * 365;

  int b = n / 30;
  n -= b * 30;

  cout << a << " ano(s)" << endl;
  cout << b << " mes(es)" << endl;
  cout << n << " dia(s)" << endl;

  return 0;
}