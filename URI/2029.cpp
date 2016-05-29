#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

#define PI 3.14

int main() {
  double v, d;
  while (cin >> v >> d) {
    double p = d * PI;
    double r = p / (2.0 * PI);
    double area = (PI * r * r);
    double h = v / area;


    printf("ALTURA = %.2lf\n", h);
    printf("AREA = %.2lf\n", area);
  }

  return 0;
}