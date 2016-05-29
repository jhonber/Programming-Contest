#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

long long solve (long long n, long long m, long long x) {
  long long ans = 0;
  if (x == 0) {
    m --;
    long long tot = 0;
    if (m - 8 >= 0) {
      tot ++;
      long long dif = m - 8;
      tot += dif / 2;
    }

    long long tot2 = 0;
    if (n - 8 >= 0) {
      tot2 ++;
      long long dif = n - 8;
      tot2 += dif / 2;
    }

    ans += tot * tot2;

    n --;
    m ++;

    tot = tot2 = 0;

    if (m - 8 >= 0) {
      tot ++;
      long long dif = m - 8;
      tot += dif / 2;
    }

    if (n - 8 >= 0) {
      tot2 ++;
      long long dif = n - 8;
      tot2 += dif / 2;
    }

    ans += tot * tot2;
  }
  else {
    long long tot = 0;
    if (m - 8 >= 0) {
      tot ++;
      long long dif = m - 8;
      tot += dif / 2;
    }

    long long tot2 = 0;
    if (n - 8 >= 0) {
      tot2 ++;
      long long dif = n - 8;
      tot2 += dif / 2;
    }

    ans += tot * tot2;
  }
  return ans;
}

int main() {
  long long n, m, x;
  while (cin >> n >> m >> x) {
    if (n + m + x == 0) break;

    long long ans1 = solve(n, m, x);
    long long ans2 = 0;

    if (x) {
      n--; m--;
      ans2 = solve(n, m, x);
    }

    cout << ans1 + ans2 << endl;
  }

  return 0;
}