// http://codeforces.com/contest/194/problem/A

#include<bits/stdc++.h>
using namespace std;
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> v(n, 0);
  int tot = 0;

  while (tot < k) {
    for (int i = 0; i < n && tot < k; ++i) {
      v[i] ++;
      tot ++;
    }
  }

  int paila = 0;
  for (int i = 0; i < n; ++i) if (v[i] == 2) paila ++;

  cout << paila;
  return 0;
}