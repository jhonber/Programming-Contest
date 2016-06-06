#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  cin >> n;

  if (n > 0) {
    cout << "Ho";
    for (int i = 1; i < n; ++i) cout << " Ho";
    cout << "!" << endl;
  }

  return 0;
}