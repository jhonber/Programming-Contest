#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int f(int x, int b) {
  if (!x) return 0;

  vector<int> v;
  while (x > 0) {
    v.push_back(x % 10);
    x /= 10;
  }

  while (v.size() < 4) v.push_back(0);

  sort(v.begin(), v.end());
  if (b) reverse(v.begin(), v.end());

  int res = 0;
  int pot = 1;
  for (int i = 3; i >= 0; --i) {
    res += v[i] * pot;
    pot *= 10;
  }

  return res;
}

int krapekar(int X) {
  int cnt = 0;

  int lim = 1000;
  while (X != 6174 && lim --> 0) {
    int hi = f(X, 1);
    int lo = f(X, 0);

    X = hi - lo;
    cnt = cnt + 1;
  }

  if (X != 6174) return -1;
  return cnt;
}

int main() {
  int t;
  cin >> t;

  int n;
  for (int i = 1; i <= t; ++i) {
    cin >> n;

    int ans = krapekar(n);
    cout << "Caso #" << i << ": " << ans << endl;
  }

  return 0;
}