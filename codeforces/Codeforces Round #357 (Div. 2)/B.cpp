// http://codeforces.com/contest/681/problem/B

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  long long n;
  cin >> n;

  long long a, b, c;
  a = 1234567;
  b = 123456;
  c = 1234;

  for (int i = 0; i < 850; ++i) {
    for (int j = 0; j < 8200; ++j) {
      long long other = (n - (i * a + j * b)) / c;
      long long tot = i * a + j * b + other * c;
      long long tot2 = i * a + j * b + (other + 1) * c;
      long long tot3 = i * a + j * b + (other - 1) * c;

      if (tot == n && other >= 0 || tot2 == n && other + 1 >= 0 && tot3 == n && other - 1 >= 0) {
        cout << "YES" << endl;
        return 0;
      }
    }
  }

  cout << "NO" << endl;
  return 0;
}