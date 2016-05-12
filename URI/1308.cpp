#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int t;
  cin >> t;

  double x;
  while (cin >> x) {
    long long r1 = -(.5) + sqrt((1/4.0) + (2 * x));
    long long r2 = -(.5) - sqrt((1/4.0) + (2 * x));

    cout << max(r1, r2) << endl;
  }

  return 0;
}