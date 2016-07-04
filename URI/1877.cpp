#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n, k;
  cin >> n >> k;

  int a, b;
  cin >> a;

  vector<int> v(n);
  for (int i = 1; i < n; ++i) cin >> v[i];

  int tot = 0;
  for (int i = 1; i + 1 < n; ++i) {
    if (v[i - 1] > v[i] && v[i] < v[i + 1]) tot ++;
  }

  if (tot + 1 == k) cout << "beautiful" << endl;
  else cout << "ugly" << endl;

  return 0;
}