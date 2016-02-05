// http://codeforces.com/contest/376/problem/C

#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() { IO
  int m = 7;
  vector<int> v = {1, 6, 8, 9};
  vector<int> p = {1, 10, 100, 1000};
  vector<int> vmod[7];

  do {
    int mod = 0;
    for (int i = 0, j = 3; i < 4; ++i, --j)
      mod += (v[j] * p[i]) % m;

    vmod[mod % m] = v;
  }
  while (next_permutation(v.begin(), v.end()));

  string s;
  cin >> s;

  vector<int> count(10, 0);
  for (int i = 0; i < s.size(); ++i) {
    count[s[i] - '0'] ++;
  }

  count[1] --;
  count[6] --;
  count[8] --;
  count[9] --;

  string ans;
  long long mod = 0;
  long long pot = 1000 * 10;
  for (int i = 1; i < 10; ++i) {
    while (count[i] --> 0) {
      pot %= m;
      mod += (i * pot) % m;
      mod %= m;
      pot *= 10;
      ans.push_back(i + '0');
    }
  }

  int ind = m - mod;
  reverse(ans.begin(), ans.end());
  cout << ans;
  if (!mod) ind = 0;
  for (int i = 0; i < 4; ++i) cout << vmod[ind][i];
  while (count[0] --> 0) cout << 0;

  return 0;
}