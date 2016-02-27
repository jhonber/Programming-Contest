#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

long long fact[1111];

long long mpow(long long b, long long e) {
  long long p = 1;
  while (e > 0) {
    if ((e & 1) != 0) 
      p = (p * b) % mod;

    e >>= 1;
    b = (b * b) % mod;
  }

  return p % mod;
}

int main() {
  string s;

  fact[0] = 1;
  for (int i = 1; i < 1111; ++i) fact[i] = (fact[i - 1] * i) % mod;

  while (cin >> s) {
    map<char, int> mapa;
    for (int i = 0; i < s.size(); ++i) {
      mapa[tolower(s[i]) -'a'] ++;
    }

    long long num = fact[(int)s.size()];
    long long den = 1;
    for (int i = 0; i < 26; ++i) den = (den * fact[mapa[i]]) % mod;

    long long ans = (num * mpow(den, mod - 2)) % mod;
    cout << ans << endl;
  }
  return 0;
}
