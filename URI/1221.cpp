#include<bits/stdc++.h>
using namespace std;

const long long mx = 2147483647;
vector<int> primes;

void gen_primes() {
  primes.push_back(2);
  long long p = 3;
  while (p * p <= mx) {
    int i = 2;;
    int f = true;
    while (i * i <= p) {
      if (p % i == 0) {
        f = false;
        break;
      }
      i ++;
    }
    if (f) primes.push_back(p);
    p += 2;
  }
}

int main() {
  gen_primes();
  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    int t;
    cin >> t;
    if (binary_search(primes.begin(), primes.end(), t)) {
      printf("Prime\n");
    }
    else {
      int f = true;
      for (int j = 0; j < primes.size(); ++j) if (t % primes[j] == 0) {
        f = false;
        break;
      }

      if (f) printf("Prime\n");
      else printf("Not Prime\n");
    }
  }

  return 0;
}