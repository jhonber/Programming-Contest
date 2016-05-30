#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n, m;
  while (cin >> n >> m) {
    if (n + m == 0) break;

    int sum = 0;
    for (int i = 0; i < n; ++i) {
      string name;
      int p;
      cin >> name >> p;
      sum += p;
    }

    cout << (3 * m) - sum << endl;
  }

  return 0;
}