#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int t, n;
  cin >> t >> n;

  while (n --> 0) {
    string s;
    cin >> s;

    if ("fechou" == s) {
      t ++;
    }
    else {
      t --;
    }
  }

  cout << max(t, 0) << endl;
  return 0;
}