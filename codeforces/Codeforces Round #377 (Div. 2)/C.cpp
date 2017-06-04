// http://codeforces.com/contest/732/problem/C

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  vector<long long> v(3);
  while (cin >> v[0] >> v[1] >> v[2]) {
    int ind = 0;
    long long mmax = -1;

    for (int i = 0; i < 3; ++i) {
      if (v[i] >= mmax) {
        mmax = v[i];
        ind = i;
      }
    }

    long long ans = 0;
    if (ind == 0) {
      mmax --;
      ans = abs(mmax - v[1]) + abs(mmax - v[2]);
    }
    else if (ind == 1) {
      ans = abs(mmax - v[0]) + abs(mmax - v[2]);
      if (v[1] >= v[2] + 1) ans --;
      if (v[1] >= v[0] + 1) ans --;
    }
    else {
      ans = abs(mmax - v[0]) + abs(mmax - v[1]);
      if (v[2] >= v[0] + 1) ans --;
      if (v[2] >= v[1] + 1) ans --;
    }

    cout << max(ans, 0LL) << endl;
  }

  return 0;
}