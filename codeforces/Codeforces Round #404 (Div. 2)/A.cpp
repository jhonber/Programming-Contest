// http://codeforces.com/contest/785/problem/A

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  cin >> n;

  map<string, long long> cnt;
  cnt["Tetrahedron"] = 4;
  cnt["Cube"] = 6;
  cnt["Octahedron"] = 8;
  cnt["Dodecahedron"] = 12;
  cnt["Icosahedron"] = 20;

  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;

    ans += cnt[s];
  }

  cout << ans << endl;

  return 0;
}