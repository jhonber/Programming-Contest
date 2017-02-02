// http://codeforces.com/contest/762/problem/A

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

long long solve (long long n, long long k) {
  if (k == 1) return 1;

  vector<long long> divs;
  divs.push_back(1);

  int kk = 1;
  long long lim = sqrt(n);
  for (long long i = 2; i <= lim; ++i) {
    if (n % i == 0) {
      divs.push_back(i);
      if (i != n / i) {
        divs.push_back(n / i);
      }

    }
  }
  divs.push_back(n);
  sort(divs.begin(), divs.end());

  if (k - 1 >= divs.size()) return -1;
  return divs[k - 1];
}

int main() {
  long long n, k;
  cin >> n >> k;

  if (n == 1) {
    if (k > 1) cout << -1 << endl;
    else cout << 1 << endl;
    return 0;
  }

  long long ans = solve(n, k);
  cout << ans << endl;
  return 0;
}