#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;
#define endl '\n'

int main() {
  long long a, b, sum;
  while (cin >> a >> b) {
    sum = 0;

    while (b > 0) {
      sum += b % 10;
      b /= 10;
    }

    cout << sum << " " << (sum % 3 == 0 ? "sim" : "nao") << endl;
  }

  return 0;
}