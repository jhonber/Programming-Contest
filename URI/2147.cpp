#include<bits/stdc++.h>
using namespace std;
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  string s;
  cin >> s;
  while (cin >> s) {
    int tot = s.size();
    cout << fixed << setprecision(2) << tot / 100.0 << endl;
  }

  return 0;
}