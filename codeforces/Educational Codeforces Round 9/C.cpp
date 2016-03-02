// http://codeforces.com/contest/632/problem/C

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;
#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);

bool comp(string a, string b) {
  return a + b < b + a;
}

int main () { IO
  int n;
  cin >> n;

  vector< string > v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];

  sort(v.begin(), v.end(), comp);
  for (int i = 0; i < n; ++i) cout << v[i];

  return 0;
}