#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;
#define IO ios::sync_with_stdio(false); cin.tie(NULL);

long long lcd(long long a, long long b) {
  return (a * b) / __gcd(a, b);
}

int main() { IO

  long long n, t;
  while (cin >> n >> t) {
    if (n + t == 0) break;

    long long m = 1;
    long long k = 0;
    long long x;
    unordered_map<int, bool> ready;
    for (int i = 0; i < n; ++i) {
      cin >> x;
      ready[x] = true;
      m = lcd(m, x);
      k = __gcd(x, k);
    }

    if (k == 1 && (t % m != 0)) {
      cout << "impossivel" << endl;
      continue;
    }

    int found = false;
    long long tmp = 0;
    for (long long i = 2; i <= 100000; ++i) {
      if (ready[i]) continue;
      tmp = lcd(m, i);
      if (tmp == t) {
        cout << i << endl;
        found = true;
        break;
      }
    }

    if (!found) cout << "impossivel" << endl;
  }

  return 0;
}