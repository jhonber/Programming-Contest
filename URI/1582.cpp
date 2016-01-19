#include<bits/stdc++.h>
using namespace std;

int main() {
  vector<int> v(3);
  while (cin >> v[0] >> v[1] >> v[2]) {
    sort(v.begin(), v.end());

    int gcd = __gcd(v[0], __gcd(v[1], v[2]));
    cout << gcd << endl;
    if (v[2] * v[2] == (v[1] * v[1]) + (v[0] * v[0])) {
      if (gcd == 1) cout << "tripla pitagorica primitiva" << endl;
      else cout << "tripla pitagorica" << endl;
    }
    else cout << "tripla" << endl;
  }

  return 0;
}
