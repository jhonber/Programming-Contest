#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  for (int k = 0; k < n; ++k) {
    string a,b;
    cin >> a >> b;

    int t = min(a.size(), b.size());
    int i;
    for (i = 0; i < t; ++i) {
      cout << a[i] << b[i];
    }

    if (a.size() > b.size()) {
      for (int j = i; j < a.size(); ++j) cout << a[j];
    }
    else {
      for (int j = i; j < b.size(); ++j) cout << b[j];
    }
    cout << endl;
  }

  return 0;
}