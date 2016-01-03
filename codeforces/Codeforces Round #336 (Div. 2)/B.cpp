// http://codeforces.com/contest/608/problem/B

#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  string a,b;
  cin >> a >> b;

  int pre[222222];
  memset(pre, 0, sizeof pre);

  for (int i = 1; i < 222222; ++i) {
    if (i <= b.size() && b[i - 1] == '1') pre[i] = pre[i - 1] + 1;
    else pre[i] = pre[i - 1];
  }

  long long ans = 0;
  for (int i = 0; i < a.size(); ++i) {
    int beg = i + 1;
    int end = b.size() - (a.size() - (i + 1));
    int ones = pre[end] - pre[beg - 1];
    if (a[i] == '0') {
      ans += ones;
    }
    else {
      int zeros = (abs(beg - end) + 1) - ones;
      ans += zeros;
    }
  }

  cout << ans;
  return 0;
}