#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int id;
  double a, b;
  cin >> id >> a >> b;

  cout << "NUMBER = " << id << endl;
  printf("SALARY = U$ %.2lf\n", a * b);

  return 0;
}