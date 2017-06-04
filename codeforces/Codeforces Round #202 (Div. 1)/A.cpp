// http://codeforces.com/contest/348/problem/A

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  while (cin >> n) {
    vector<int> v(n);

    long long sum = 0;
    int mmax = -1;
    for (int i = 0; i < n; ++i) {
      cin >> v[i];
      mmax = max(v[i], mmax);
      sum += v[i];
    }

    long long ans = (sum - 1) / (n - 1);
    ans ++;

    cout << max(ans, (long long)mmax) << endl;
  }

  return 0;
}