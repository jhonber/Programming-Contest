// http://codeforces.com/contest/222/problem/B

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() { IO
  int n, m, k;
  cin >> n >> m >> k;

  vector<int> rows(1111), cols(1111);
  int table[1111][1111];

  for (int i = 1; i <= n; ++i) rows[i] = i;
  for (int i = 1; i <= m; ++i) cols[i] = i;

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> table[i][j];
    }
  }

  char op;
  int a, b;
  while (k --> 0) {
    cin >> op >> a >> b;

    if (op == 'g') {
      cout << table[rows[a]][cols[b]] << endl;
      continue;
    }

    if (op == 'c') {
      swap(cols[a], cols[b]);
    }
    else {
      swap(rows[a], rows[b]);
    }
  }

  return 0;
}