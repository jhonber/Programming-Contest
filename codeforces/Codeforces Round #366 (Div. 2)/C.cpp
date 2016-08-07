// http://codeforces.com/contest/705/problem/C

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() { IO
  int n, q;
  cin >> n >> q;

  vector<int> arr(333000, 0);
  unordered_map<int, vector<int>> apps;
  int unread = 0;
  int lastRead = 0;

  int ind = 0;
  for (int i = 0; i < q; ++i) {
    int op, x;
    cin >> op >> x; x--;

    if (op == 1) {
      apps[x].push_back(ind);
      arr[ind] ++;
      unread ++;
      ind ++;
    }
    else if (op == 2) {
      if (apps.count(x) > 0) {
        vector<int> v = apps[x];
        apps[x].clear();

        for (auto j: v) {
          unread -= arr[j];
          arr[j] = 0;
        }
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