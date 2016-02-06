#include<bits/stdc++.h>
using namespace std;

const int mx = 1e9 + 10;
vector<int> primes;

void gen() {
  primes.push_back(2);
  for (int p = 3; p * p <= mx; p += 2) {
    int i = 2;
    int f = true;
    while (i * i <= p) {
      if (p % i == 0) {
        f = false;
        break;
      }
      i ++;
    }

    if (f) primes.push_back(p);
  }
}

bool isPrime(int x) {
  if (x == 2) return true;

  int i = 0;
  while (i < primes.size() && primes[i] * primes[i] <= x) {
    if (x % primes[i] == 0) return false;
    i ++;
  }
  return true;
}

int main() {
  gen();
  int t;
  scanf("%d", &t);

  int n, m;
  while (t --> 0) {
    scanf("%d %d", &n, &m);

    if (n <= 2) {
      printf("2\n");
      n = 3;
    }

    if (n % 2 == 0) n ++;
    for (int i = n; i <= m; i += 2) {
      if (isPrime(i)) printf("%d\n", i);
    }
    printf("\n");
  }

  return 0;
}
