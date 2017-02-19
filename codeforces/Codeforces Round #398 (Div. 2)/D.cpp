// http://codeforces.com/contest/767/problem/D

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

struct milk {
  int i, d;
  milk() {d = INT_MAX;}
  milk(int a, int b) {
    i = a;
    d = b;
  }

  bool operator < (const milk &other) const {
    return d < other.d;
  }
};

int get_item (int &day, vector<milk> &fridge, vector<milk> &shop) {
  while (shop.size() > 0 && shop.back().d < day) shop.pop_back();

  milk a, b; a = b = milk();
  if (fridge.size() > 0) a = fridge.back();
  if (shop.size() > 0) b = shop.back();

  if (a.d < day) {
    return -1;
  }

  if (a.d != INT_MAX && a.d <= b.d) {
    fridge.pop_back();
    return 0;
  }
  else if (b.d != INT_MAX) {
    shop.pop_back();
    return b.i;
  }

  return 0;
}

int main() { IO
  int n, m, k;
  cin >> n >> m >> k;

  vector<milk> fridge(n), shop(m);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    fridge[i] = milk(i + 1, x);
  }

  for (int i = 0; i < m; ++i) {
    int x;
    cin >> x;
    shop[i] = milk(i + 1, x);
  }

  sort(fridge.begin(), fridge.end());
  sort(shop.begin(), shop.end());

  reverse(fridge.begin(), fridge.end());
  reverse(shop.begin(), shop.end());

  bool ok = true;
  int lim = 1e7 + 10;
  int tot = 0;
  vector<int> ans(lim, 0);

  for (int day = 0; day < lim && ok; ++day) {
    for (int i = 0; i < k; ++i) {
      if (fridge.size() == 0 && shop.size() == 0) break;
      int cur = get_item(day, fridge, shop);
      if (cur == -1) {
        ok = false;
        break;
      }

      if (cur) {
        ans[cur] = 1;
        tot ++;
      }
    }
  }

  if (ok) {
    cout << tot << endl;
    for (int i = 0; i < ans.size(); ++i) if (ans[i]) cout << i << " "; cout << endl;
  }
  else cout << -1 << endl;

  return 0;
}