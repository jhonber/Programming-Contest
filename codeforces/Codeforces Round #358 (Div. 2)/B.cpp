// http://codeforces.com/contest/682/problem/B

#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;
#define endl '\n'

int main() {
  int n;
  cin >> n;

  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }

  sort(v.begin(), v.end());

  int f = true;
  for (int i = 1; i <= n; ++i) {
    if (v[i - 1] < i) {
      f = false;
      break;
    }
  }

  if (f) {
    cout << n + 1 << endl;
    return 0;
  }

  int ind = 0;
  int i;
  for (i = 1; i <= n && ind < n; ++ind) {
    if (v[ind] >= i) {
      i ++;
    }
  }

  cout << i << endl;

  return 0;
}