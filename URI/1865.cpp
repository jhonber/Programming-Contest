#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    string nn;
    int x;
    cin >> nn >> x;
    if (nn == "Thor") {
      cout << "Y";
    }
    else cout << "N";
    cout << endl;
  }
  return 0;
}

