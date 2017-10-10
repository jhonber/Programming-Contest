// https://www.urionlinejudge.com.br/judge/en/problems/view/1904
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

const int mx = 1e7 + 10;
long long fact[mx];

vector<long long> primes;
long long cnt_primes[mx];
vector<long long> criba(mx, true);

// test parity for C(n, k)
bool calc (long long n, long long k) {
  return (k & (n - k)) ? 0 : 1;
}

long long count_primes (long long a, long long b) {
  return cnt_primes[b] - cnt_primes[a - 1];
}

void gen_primes () {
  for (int i = 2; i < mx; ++i) {
    if (criba[i]) {
      int j = 2;
      while (i * j < mx) {
        criba[i * j] = false;
        j ++;
      }
    }
  }

  criba[0] = criba[1] = 0;
}

int main() {
  gen_primes();
  long long a, b;

  for (int i = 1; i < mx; ++i) {
    criba[i] += criba[i - 1];
  }

  while (cin >> a >> b) {
    if (a > b) swap(a, b);

    if (a == b) {
      cout << "?" << endl;
      continue;
    }


    long long n = b - a;
    long long r = criba[b] - criba[max(0LL, a - 1)];

    //  |n+r-1|    (n+r-1)!           |n+r-1|       n!
    //  |     | = ----------    =     |     | = ----------
    //  |  r  |   r! * (n-1)!         |  n  |   r! * (n-r)!
    //
    //  from stars and bars Theorem

    bool ans = calc(n + r - 1, n);

    cout << (ans ? "Alice" : "Bob") << endl;
  }
  return 0;
}
