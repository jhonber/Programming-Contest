// https://www.hackerrank.com/contests/infinitum8/challenges/pairwise-sum-and-divide

#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << (#x) << " = " << (x) << endl;

int main() {
  int tc,n;
  cin >> tc;

  while (tc --> 0) {
    cin >> n;
    int v[n];

    int ones[n + 10];
    int twos[n + 10];

    ones[0] = twos[0] = 0;
    for (int i = 1; i <= n; ++i) {
      cin >> v[i - 1];
      if (v[i - 1] == 1) ones[i] = ones[i - 1] + 1;
      else ones[i] = ones[i - 1];

      if (v[i - 1] == 2) twos[i] = twos[i - 1] + 1;
      else twos[i] = twos[i - 1];
    }

    long long ans = 0;
    for (int i = 0; i < n; ++i) {
      int howOnes = ones[n] - ones[i + 1];
      int howTwos = twos[n] - twos[i + 1];

      if (v[i] == 1) ans += (n - (i + 1)) + howOnes;
      else if (v[i] == 2) ans += howTwos + howOnes;
      else ans += howOnes;
    }

    cout << ans << endl;
  }
  return 0;
}
