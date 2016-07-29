// http://codeforces.com/contest/702/problem/A

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  cin >> n;

  vector<int> v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];

  int ans = 1;
  int i = 0;
  int j = 1;

  while (i < n && j < n) {
    while (j < n && v[j - 1] < v[j]) j++;

    ans = max(ans, j - i);
    i = j;
    j ++;
  }

  cout << ans << endl;
  return 0;

}