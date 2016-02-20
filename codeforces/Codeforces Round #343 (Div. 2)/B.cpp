// http://codeforces.com/contest/629/problem/B

#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  cin >> n;

  int ans = 0;
  vector< pair<int, int> > M, F;
  for (int i = 0; i < n; ++i) {
    char c;
    int a,b;
    cin >> c >> a >> b;

    if (c == 'M') M.push_back({a, b});
    else F.push_back({a, b});
  }


  for (int i = 1; i <= 366; ++i) {
    int m = 0;
    int f = 0;
    for (int j = 0; j < M.size(); ++j) {
      int a = M[j].first;
      int b = M[j].second;
      if (i >= a && i <= b) {
        m ++;
      }
    }

    for (int j = 0; j < F.size(); ++j) {
      int a = F[j].first;
      int b = F[j].second;
      if (i >= a && i <= b) {
        f ++;
      }
    }

    int tot = min(f, m);
    ans = max(ans, tot);
  }

  cout << ans * 2;

  return 0;
}