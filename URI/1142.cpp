#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  cin >> n;

  int num = 1;
  for (int i = 1; i <= n*3; ++i) {
    cout << num << " ";
    if (i % 3 == 0) {
      cout << "PUM" << endl;
      num ++;
    }
    num ++;
  }

  return 0;
}