#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

const int inf = 1e6;
const int N = 3 * 1e5; // size for ans[]

//             0,n-1
//            [l, r)
int query (int x, int y, int id, int l, int r, vector<int> &ans) {
  if (l >= y || x >= r) return inf;
  if (x <= l && r <= y) return ans[id];

  int mid = (l + r) / 2;
  int a = query (x, y, 2 * id, l, mid, ans);
  int b = query (x, y, 2 * id + 1, mid, r, ans);

  return min(a, b);
}

void init (int id, int l, int r, vector<int> &v, vector<int> &ans) {
  if (v.size() == 0) return;

  if (r - l < 2) {
    ans[id] = v[l];
    return;
  }

  int mid = (r + l) / 2;
  init (2 * id, l, mid, v, ans);
  init (2 * id + 1, mid, r, v, ans);

  ans[id] = min(ans[2 * id], ans[2 * id + 1]);
}

int main() {
  int n, k;
  while (cin >> n >> k) {
    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];

    vector<int> ans(N, 0);
    init (1, 0, n, v, ans);

    for (int i = 0; i < n; ++i) {
      int l = i;
      int r = min(i + k + 1, n);
      int m = query(l, r, 1, 0, n, ans);

      if (m < v[i]) {
        r --;
        while (l <= r) {
          if (v[r] == m) {
            swap(v[r], v[i]);
            break;
          }

          r --;
        }

        break;
      }
    }

    for (auto i: v) cout << i << " "; cout << endl;
  }

  return 0;
}
