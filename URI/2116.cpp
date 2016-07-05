#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;
#define IO ios::sync_with_stdio(false); cin.tie(NULL);

vector<int> primes;
void gen () {
  primes.push_back(2);
  for (int i = 3; i <= 2000; i += 2) {
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

int main() { IO
  int n, m;
  gen();
  while (cin >> n >> m) {
    int a, b;
    for (int i = 0; i < primes.size(); ++i) {
      if (primes[i] > n) break;
      a = primes[i];
    }

    for (int i = 0; i < primes.size(); ++i) {
      if (primes[i] > m) break;
      b = primes[i];
    }

    cout << a * b << endl;
  }

  return 0;
}