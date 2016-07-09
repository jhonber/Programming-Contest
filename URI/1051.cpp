#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;
#define IO ios::sync_with_stdio(false); cin.tie(NULL);

int main() {
  double x;
  cin >> x;

  cout << fixed << setprecision(2);

  if (x <= 2000) {
    cout << "Isento" << endl;
    return 0;
  }

  double ans = 0;
  if (x > 2000) {
    double t = x - 2000;
    if (t > 1000) t = 1000;
    ans += t * .08;
  }

  if (x > 3000) {
    double t = x - 3000;
    if (t > 1500) t = 1500;
    ans += t * .18;
  }

  if (x > 4500) {
    double t = x - 4500;
    ans += t * .28;
  }

  cout << "R$ " << ans << endl;

  return 0;
}