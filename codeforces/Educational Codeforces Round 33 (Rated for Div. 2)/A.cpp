// http://codeforces.com/contest/893/problem/A
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) <<  endl;

int main() {
#ifdef ONLINEJUDGE
  ios_base::sync_with_stdio(0); cin.tie(0);
#endif

  int n;
  cin >> n;

  bool ok = true;
  vector<int> v = {1, 1, 0};
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x; x--;

    if (!v[x]) ok = false;

    v[x] ++;
    for (int j = 0; j < 3; ++j) {
      if (!v[j]) {
        v[j] = v[x];
      }
    }

    for (int i = 0; i < 3; ++i) v[i] --;
  }

  cout << (ok ? "YES" : "NO") << endl;

  return 0;
}
