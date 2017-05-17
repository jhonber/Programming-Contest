// http://codeforces.com/contest/808/problem/D

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  long long n;
  while (cin >> n) {
    map<long long, int> R, L;
    vector<long long> v(n);

    long long tot = 0;
    for (int i = 0; i < n; ++i) cin >> v[i];
    for (int i = n - 1; i >= 0; --i) {
      if (R[v[i]] == 0)
        R[v[i]] = i + 1;
      if (L[v[n - i - 1]] == 0)
        L[v[n - i - 1]] = n - i;

      tot += v[i];
    }

    long long pre = 0;
    bool ok = false;
    for (int i = 1; i <= n; ++i) {
      pre += v[i - 1];
      long long right = tot - pre;
      long long left = pre;
      long long x = (right - left) / 2;

      if (right == left) {
        ok = true;
        break;
      }

      if ((right - left) % 2 == 0) {
        if (x > 0){
          if (R[x] && R[x] > i) {
            ok = true;
            break;
          }
        }
        else {
          x = abs(x);
          if (L[x] && L[x] < i) {
            ok = true;
            break;
          }
        }
      }
    }

    cout << (ok ? "YES" : "NO") << endl;
  }

  return 0;
}
