// http://codeforces.com/contest/639/problem/A

#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n, k, q;
  cin >> n >> k >> q;

  map<int, int> all;
  for (int i = 0 ; i < n; ++i) {
    int a;
    cin >> a;
    all[i + 1] = a;
  }

  set<int> online;
  for (int i = 0; i < q; ++i) {
    int a, b;
    cin >> a >> b;

    if (a == 1) {
      if (online.size() < k)
        online.insert(all[b]);
      else {
        set<int> :: iterator it = online.begin();
        if (*it < all[b]) {
          online.erase(it);
          online.insert(all[b]);
        }
      }
    }
    else {
      if (online.count(all[b]) > 0) cout << "YES" << endl;
      else cout << "NO" << endl;
    }
  }

  return 0;
}