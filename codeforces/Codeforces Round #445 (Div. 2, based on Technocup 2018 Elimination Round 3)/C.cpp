// http://codeforces.com/contest/890/problem/C

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  while (cin >> n) {
    vector<int> v(n + 1);
    v[0] = 0;
    for (int i = 0; i < n; ++i) cin >> v[i + 1];

    int cnt = 1;
    vector<int> times(n + 1, 0);
    for (int i = n; i > 0; --i) {
      int ind = v[i];
      if (!times[i])
        times[i] = cnt;

      while (times[ind] == 0) {
        times[ind] = cnt;
        ind = v[ind];
      }

      cnt ++;
    }

    set<int> tot(times.begin(), times.end());
    cout << tot.size() << endl;
  }

  return 0;
}