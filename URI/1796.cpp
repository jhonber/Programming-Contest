#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    int t;
    cin >> t;
    cnt += t;
  }

  if (n - cnt > n / 2)  cout << "Y" << endl;
  else cout << "N" << endl;
  return 0;
}
