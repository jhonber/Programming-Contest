#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int t;
  cin >> t;

  unsigned long long n;
  while (t --> 0) {
    cin >> n;

    unsigned long long ans = (1ULL << n) - 1;
    if (n == 64) ans --;

    cout << ans / (1000 * 12) << " kg" << endl;
  }

  return 0;
}