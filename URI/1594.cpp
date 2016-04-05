#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x " = " << (x) << endl;

int main() {
  int tc;
  cin >> tc;

  while (tc --> 0) {
    int n, k, s;
    cin >> n >> k >> s;

    vector<long long> v(n);
    v[0] = s;
    for (int i = 1; i < n; ++i)
      v[i] = (1LL*v[i-1]*1103515245 + 12345) % (2147483648LL);

    deque<long long> Q;
    int i;
    for (i = 0; i < k; ++i) {
      while (!Q.empty() && v[i] >= v[Q.back()])
        Q.pop_back();

      Q.push_back(i);
    }

    long long ans = 0;
    for ( ; i < n; ++i) {
      ans += v[Q.front()];

      while (!Q.empty() && Q.front() <= i - k)
        Q.pop_front();

      while (!Q.empty() && v[i] >= v[Q.back()])
        Q.pop_back();

      Q.push_back(i);
    }

    ans += v[Q.front()];
    cout << ans << endl;
  }

  return 0;
}