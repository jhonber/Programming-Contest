#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " < (x) << endl;

int main() {
  int n;
  cin >> n;

  int tot = 0;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;

    if (a >= 10 && a <= 20) tot ++;
  }


  cout << tot << " in" << endl;
  cout << n - tot << " out" << endl;
  return 0;
}