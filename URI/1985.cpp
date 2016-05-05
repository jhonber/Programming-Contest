#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {

  map<int, double> mapa;
  mapa[1001] = 1.50;
  mapa[1002] = 2.50;
  mapa[1003] = 3.50;
  mapa[1004] = 4.50;
  mapa[1005] = 5.50;

  int n;
  cin >> n;

  double ans = 0;
  while (n --> 0) {
    int a;
    double b;

    cin >> a >> b;
    ans += b * mapa[a];
  }

  printf("%.2lf\n", ans);

  return 0;
}