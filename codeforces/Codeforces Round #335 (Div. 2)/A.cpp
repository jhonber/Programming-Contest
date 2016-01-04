// http://codeforces.com/contest/606/problem/A

#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int v[3];
  cin >> v[0] >> v[1] >> v[2];

  int vv[3];
  cin >> vv[0] >> vv[1] >> vv[2];

  int need = 0;
  int have = 0;
  for (int i = 0; i < 3; ++i) {
    if (v[i] > vv[i]) have += (v[i] - vv[i]) / 2;
    else need += vv[i] - v[i];
  }

  if (have >= need) cout << "Yes";
  else cout << "No";

  return 0;
}