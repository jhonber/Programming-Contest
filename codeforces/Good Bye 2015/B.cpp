// http://codeforces.com/contest/611/problem/B

#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

vector<long long> gen() {
  vector<long long> ans;
  ans.push_back(2);
  for (int i = 2; i <= 60; ++i) {
    long long t = (2LL << i) - 1;
    ans.push_back(t - 1);
    for (int j = 0; j < i - 1; ++j) {
      long long other = t - (2LL << j);
      ans.push_back(other);
    }
  }

  sort(ans.begin(), ans.end());
  return ans;
}


int main() {
  vector<long long> v = gen();
  long long a, b;
  cin >> a >> b;

  int ans = 0;
  for (int i = 0; i < v.size(); ++i) if (v[i] >= a && v[i] <= b) ans ++;

  cout << ans;
  return 0;
}