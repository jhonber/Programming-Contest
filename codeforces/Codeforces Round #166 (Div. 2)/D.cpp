// http://codeforces.com/contest/271/problem/D

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

typedef unsigned long long ll;

int main() {
  int k;
  string a, b;

  cin >> a >> b >> k;

  ll p1 = 787, p2 = 797;
  set<pair<ll, ll>> ans;
  ll h_a, h_b, pot1, pot2;

  for (int i = 1; i <= a.size(); ++i) {
    int bad = 0;
    h_a = 0;
    h_b = 0;
    pot1 = 1;
    pot2 = 1;
    for (int j = i; j <= a.size(); ++j) {
      int ind = a[j - 1] - 'a';
      bad += (b[ind] == '0' ? 1 : 0);
      if (bad > k) break;

      h_a += (ind + 1ULL) * pot1;
      h_b += (ind + 1ULL) * pot2;

      ans.insert({h_a, h_b});
      pot1 *= p1;
      pot2 *= p2;
    }
  }

  cout << ans.size() << endl;
  return 0;
}