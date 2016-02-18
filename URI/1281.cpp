#include<bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) {
    int n;
    cin >> n;

    map<string, double> mapa;
    for (int j = 0; j < n; ++j) {
      string a;
      double b;
      cin >> a >> b;
      mapa[a] = b;
    }

    int m;
    cin >> m;

    double ans = 0;
    for (int j = 0; j < m; ++j) {
      string a;
      int b;
      cin >> a >> b;
      ans += mapa[a] * b;
    }

    printf("R$ %.2lf\n", ans);
  }

  return 0;
}