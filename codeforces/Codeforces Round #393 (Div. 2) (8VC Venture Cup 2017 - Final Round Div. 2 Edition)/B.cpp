// http://codeforces.com/contest/760/problem/B

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

typedef long long ll;

ll sum (ll n) {
  if (n < 0) return 0LL;
  return (n * (n + 1)) / 2;
}

ll f (ll x, ll n, ll k) {
  ll left  = sum(x - 1) - sum(x - k);
  ll right = sum(x) - sum(x - n + k - 1);

  return left + right;
}

int main() {
  ll n, m, k;
  cin >> n >> m >> k;

  m -= n;

  if (!m) {
    cout << 1 << endl;
    return 0;
  }

  ll lo = 0;
  ll hi = 1e9;
  ll mid;

  while (lo <= hi) {
    mid = (lo + hi) / 2;
    ll tot = f(mid, n, k);

    if (tot > m) {
      hi = mid - 1;
    }
    else {
      lo = mid + 1;
    }
  }

  if (f(mid, n, k) <= m) cout << mid + 1;
  else cout << mid;
  cout << endl;
  return 0;
}