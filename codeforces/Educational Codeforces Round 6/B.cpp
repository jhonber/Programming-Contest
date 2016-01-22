// http://codeforces.com/contest/620/problem/B

#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(NULL); cie.tie(false);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;



int main() {
  int a, b;
  cin >> a >> b;

  int pre[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

  int ans = 0;
  for (int i = a; i <= b; ++i) {
    int cur = i;
    while (cur) {
      ans += pre[cur % 10];
      cur /= 10;
    }
  }

  cout << ans;
  return 0;
}