// http://codeforces.com/contest/697/problem/A

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
  long long t, s, x;
  while (cin >> t >> s >> x) {
    if (s == 0 || x == t) {
      cout << "YES" << endl;
      continue;
    }

    long long k = (x - t) / s;
    long long ti = k * 2;
    if (k > 0 && t + s * k == x || (ti > 0 && ti % 2 == 0 && t + s * k + 1 == x)) cout << "YES" << endl;
    else cout << "NO" << endl;
  }

  return 0;
}