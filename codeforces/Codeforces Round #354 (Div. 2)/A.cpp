// http://codeforces.com/contest/676/problem/A

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  cin >> n;

  int a = 0, b = 0;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
    if (v[i] == 1) a = i;
    if (v[i] == n) b = i;
  }

  if (a > b) {
    cout << max(a, (n - b) - 1) << endl;
  }
  else {
    cout << max(b, (n - a) - 1) << endl;
  }

  return 0;
}