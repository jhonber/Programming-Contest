// http://codeforces.com/contest/686/problem/B

#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];

  int found = true;
  while (found) {
    found = false;
    for (int i = 0; i + 1 < n; ++i) {
      if (v[i] > v[i + 1]) {
        found = true;
        swap(v[i], v[i + 1]);
        cout << i + 1 << " " << i + 2 << endl;
      }
    }
  }

  return 0;
}