// http://codeforces.com/contest/659/problem/C

#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  long long n, m;
  cin >> n >> m;

  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }

  sort(v.begin(), v.end());
  v.push_back(1000000000);

  vector<int> ans;
  long long sum = 0;
  int a = 1;
  for (int i = 0; i < n + 1; ++i) {
    int y = v[i];
    for (int x = a; x < y && sum + x <= m; ++x) {
      ans.push_back(x);
      sum += x;
    }
    a = v[i] + 1;
  }

  cout << ans.size() << endl;
  for (int i =0 ; i < ans.size(); ++i) cout << ans[i] << " ";

  return 0;
}