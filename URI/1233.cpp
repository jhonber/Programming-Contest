// https://www.urionlinejudge.com.br/judge/en/problems/view/1233

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

vector<long long> primes;

void gen_primes () {
  int lim = 50000;
  primes.push_back(2);

  for (int i = 3; i <= lim; i += 2) {
    int j = 2;
    int f = true;
    while (j * j <= i) {
      if (i % j == 0) {
        f = false;
        break;
      }
      j ++;
    }

    if (f) primes.push_back(i);
  }
}

long long totient (long long n) {
  if (n == 1) return 0;
  long long ans = n;
  for (int i = 0; primes[i] * primes[i] <= n; ++i) {
    if ((n % primes[i]) == 0) {
      while ((n % primes[i]) == 0) n /= primes[i];
      ans -= ans / primes[i];
    }
  }

  if (n > 1) {
    ans -= ans / n;
  }

  return ans / 2;
}

int main() {
  long long n;

  gen_primes();
  while (cin >> n) {
    cout << totient(n) << endl;
  }

  return 0;
}
