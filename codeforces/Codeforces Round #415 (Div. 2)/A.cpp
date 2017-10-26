// http://codeforces.com/contest/810/problem/A

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  double n, k;
  while (cin >> n >> k) {
    double sum = 0;
    for (int i = 0; i < n; ++i) {
      double x;
      cin >> x;
      sum += x;
    }

    double t = n;
    while (round(sum / t) != k) {
      sum += k;
      t ++;
    }

    cout << (int)t - n << endl;
  }

  return 0;
}