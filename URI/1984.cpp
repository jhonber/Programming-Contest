#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  string n;
  while (cin >> n) {
    reverse(n.begin(), n.end());
    cout << n << endl;
  }

  return 0;
}