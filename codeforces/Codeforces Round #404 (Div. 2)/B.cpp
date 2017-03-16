// http://codeforces.com/contest/785/problem/B

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n, m;
  cin >> n;

  vector<pair<int, int>> chess(n), chess2(n);

  for (int i = 0; i < n; ++i) {
    int l, r;
    cin >> l >> r;

    chess[i] = {r, l};
    chess2[i] = {l, r};
  }

  cin >> m;
  vector<pair<int, int>> prog(m), prog2(m);

  for (int i = 0; i < m; ++i) {
    int l, r;
    cin >> l >> r;

    prog[i] = {l, r};
    prog2[i] = {r, l};
  }

  sort(chess.begin(), chess.end());
  sort(prog.begin(), prog.end());

  sort(chess2.begin(), chess2.end());
  sort(prog2.begin(), prog2.end());

  int ans1 = max(0, prog[m - 1].first - chess[0].first);
  int ans2 = max(0, chess2[n - 1].first - prog2[0].first);

  cout << max(ans1, ans2) << endl;
  return 0;
}