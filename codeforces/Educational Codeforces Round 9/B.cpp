// http://codeforces.com/contest/632/problem/B

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;
#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);

int main() {
  int n;
  cin >> n;

  vector<int> v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];

  string s;
  cin >> s;

  long long a = 0;
  long long b = 0;

  for (int i = 0; i < n; ++i) {
    if (s[i] == 'A') a += v[i];
    else b += v[i];
  }

  long long aa = a;
  long long ans1 = a;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'A') {
      aa -= v[i];
    }
    else {
      aa += v[i];
    }

    ans1 = max(ans1, aa);
  }

  aa = a;
  long long ans2 = a;

  for (int i = n - 1; i >= 0; --i) {
    if (s[i] == 'A') {
      aa -= v[i];
    }
    else {
      aa += v[i];
    }

    ans2 = max(ans2, aa);
  }



  cout << max(ans1, ans2) << endl;
  return 0;
}