#include<bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t --> 0) {
    int n;
    cin >> n;

    vector<double> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];

    double avg = accumulate(v.begin(), v.end(), 0) / (double)n;
    int paila = 0;
    for (int i = 0; i < n; ++i) {
      if (v[i] > avg) paila ++;
    }

    double ans = (100.0 * paila) / n;
    printf("%.3lf%\n", ans);
  }

  return 0;
}