#include<bits/stdc++.h>
using namespace std;

int main () {
  int n;
  cin >> n;
  int ans = 1;
  int mx = INT_MAX ;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    if (a < mx) {
      mx = a;
      ans = i + 1;
    }
  }
  cout << ans << endl;
}