#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  vector<int> ans;

  ans.push_back(min(a + c, min(b, d)));
  ans.push_back(min(a + d, min(b, c)));
  ans.push_back(min(b + c, min(a, d)));
  ans.push_back(min(b + d, min(a, c)));

  sort(ans.begin(), ans.end());
  reverse(ans.begin(), ans.end());

  cout << ans[0] * ans[0] << endl;
  return 0;
}