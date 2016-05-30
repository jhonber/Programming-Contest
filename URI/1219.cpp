#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

#define PI 3.141592653589793

int main() {
  double a, b, c;
  while (cin >> a >> b >> c) {
    double p = (a + b + c) / 2.0;
    double r1 = (a * b * c) / sqrt((a+b+c) * (b+c-a) * (c+a-b) * (a+b-c));
    double a1 = PI * r1 * r1;
    double a2 = sqrt(p * (p-a) * (p-b) * (p-c));

    a1 -= a2;

    double r2 = 0.5 * sqrt(((b+c-a) * (c+a-b) * (a+b-c)) / (a+b+c));
    double a3 = r2 * r2 * PI;

    a2 -= a3;
    cout << fixed << setprecision(4) << a1 << " " << a2 << " " << a3 << endl;
  }

  return 0;
}