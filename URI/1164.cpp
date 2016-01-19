#include<bits/stdc++.h>
using namespace std;

bool good (long long n) {
  long long s = 0;
  long long i = 1;
  while (i * i <= n) {
    if (n % i == 0) {
      s += i;
      if (n / i != n) s += n / i;
    }
    i ++;
  }

  if (n == s) return true;
  return false;
}

int main() {
  int tc;
  cin >> tc;
  long long n;

  while (tc --> 0){
    cin >> n;
    cout << n << " ";
    if (good(n) && n != 1) cout << "eh perfeito" << endl;
    else cout << "nao eh perfeito" << endl;
  }

  return 0;
}
