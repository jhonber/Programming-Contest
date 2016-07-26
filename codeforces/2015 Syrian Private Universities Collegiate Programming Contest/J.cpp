#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int t;
  cin >> t;

  while (t --> 0) {
    long long a, b;
    cin >> a >> b;

    if (__gcd(a, b) == 1) cout << "GOOD" << endl;
    else cout << "NOT GOOD" << endl;
  }

  return 0;
}
