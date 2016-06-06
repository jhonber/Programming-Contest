#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  string ans = "life is not a Problem to BE solved";
  for (int i = 0; i < ans.size(); ++i) ans[i] = char(toupper(ans[i]));

  int n;
  cin >> n;

  cout << ans.substr(0, n) << endl;
  return 0;
}