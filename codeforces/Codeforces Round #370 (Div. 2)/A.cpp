// http://codeforces.com/contest/712/problem/A

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  cin >> n;

  vector<long long> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }

  vector<long long> ans(n);
  ans[n - 1] = v[n - 1];

  long long a = 0;
  long long b = 0;
  int cnt = 0;
  for (int i = n - 2; i >= 0; --i) {
    if (cnt % 2 == 0) {
      a += ans[i + 1];
      b -= ans[i + 1];
      ans[i] = v[i] + a;
    }
    else {
      a -= ans[i + 1];
      b += ans[i + 1];
      ans[i] = v[i] + b;
    }

    cnt ++;
  }

  for (int i = 0; i < n; ++i) cout << ans[i] << " "; cout << endl;
  return 0;
}