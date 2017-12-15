// http://codeforces.com/contest/893/problem/B
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) <<  endl;

int main() {
#ifdef ONLINEJUDGE
  ios_base::sync_with_stdio(0); cin.tie(0);
#endif

  int n;
  cin >> n;

  long long ans = 0;
  int i = 1;
  while (true) {
    long long a = (1LL << i) - 1;
    long long b = 1LL << (i - 1);
    if (a * b > n) break;
    if (n % (a * b) == 0) {
      ans = max(ans, a * b);
    }

    i ++;
  }

  cout << ans << endl;
  return 0;
}
