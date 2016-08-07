// http://codeforces.com/contest/705/problem/C

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n, q;
  cin >> n >> q;

  vector<int> arr(333000, 0);
  map<int, set<int>> apps;
  int unread = 0;
  int lastRead = 0;

  int ind = 0;
  for (int i = 0; i < q; ++i) {
    int op, x;
    cin >> op >> x; x--;

    if (op == 1) {
      apps[x].insert(ind);
      arr[ind] ++;
      unread ++;
      ind ++;
    }
    else if (op == 2) {
      set<int> st = apps[x];
      apps[x].clear();

      for (auto j: st) {
        unread -= arr[j];
        arr[j] = 0;
      }
    }
    else {
      while (lastRead <= x) {
        unread -= arr[lastRead];
        arr[lastRead] = 0;
        lastRead ++;
      }
    }

    cout << unread << endl;
  }

  return 0;
}