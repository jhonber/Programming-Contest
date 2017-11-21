// http://codeforces.com/contest/890/problem/B

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  while (cin >> n) {
    vector<int> v(n);
    set<int> all;
    for (int i = 0; i < n; ++i) {
      cin >> v[i];
      all.insert(v[i]);
    }

    int tot = all.size();
    set<int> ready;
    for (int i = n - 1; i >= 0; --i) {
      if (ready.size() == tot - 1 && ready.count(v[i]) == 0) {
        cout << v[i] << endl;
        break;
      }
      ready.insert(v[i]);
    }
  }

  return 0;
}