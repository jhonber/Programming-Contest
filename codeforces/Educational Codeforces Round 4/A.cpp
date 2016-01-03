// http://codeforces.com/contest/612/problem/A

#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(NULL); cie.tie(false);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

pair<int, int> check(int &p, int &q, int &n) {
  for (int i = 0; i < 1000; ++i) {
    for (int j = 0; j < 1000; ++j) {
      if (i * p + j * q == n) {
        return {i, j};
      }
    }
  }
  return {-1, -1};
}


int main() {
  int n,p,q;
  cin >> n >> p >> q;

  string s;
  cin >> s;

  vector<string> ans;
  if (n % p == 0) {
    for (int i = 0; i < n; ) {
      ans.push_back(s.substr(i, p));
      i += p;
    }
  }
  else if (n % q == 0) {
    for (int i = 0; i < n; ) {
      ans.push_back(s.substr(i, q));
      i += q;
    }
  }
  else {
    pair<int, int> ans = check(p, q, n);
    if (ans.first == -1 && ans.second == -1) cout << -1;
    else {
      cout << ans.first + ans.second << endl;
      int ind = 0;
      for (int i = 0; i < ans.first; ++i) {
        cout << s.substr(ind, p) << endl;
        ind += p;
      }

      for (int i = 0; i < ans.second; ++i) {
        cout << s.substr(ind, q) << endl;
        ind += q;
      }
    }

    return 0;
  }

  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); ++i) cout << ans[i] << endl;
  return 0;
}