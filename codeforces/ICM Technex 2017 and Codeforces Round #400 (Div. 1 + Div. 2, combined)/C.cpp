// http://codeforces.com/contest/776/problem/C

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
  int n, k;
  cin >> n >> k;

  vector<long long> pot;
  if (k == -1) {
    pot.push_back(1);
    pot.push_back(-1);
  }
  else if (k == 0 || k == 1) {
    pot.push_back(1);
  }
  else {
    long long p = 1;
    while (p < 1e16) {
      pot.push_back(p);
      p *= k;
    }
  }

  long long ans = 0;
  long long sum = 0;
  map<long long, long long> cnt;
  cnt[0] ++;

  long long a;
  for (int i = 0; i < n; ++i) {
    cin >> a;
    sum += a;
    cnt[sum] ++;

    for (int j = 0; j < pot.size(); ++j) {
      long long x = sum - pot[j];
      if (cnt.count(x) > 0) ans += cnt[x];
    }
  }

  cout << ans << endl;

  return 0;
}