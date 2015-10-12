#include<bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define foreach(it, x) for (__typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define all(x) x.begin(),x.end()
#define D(x) cout << #x " = " << (x) << endl;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

int dx[8] = {-1,-1,-1,0,1,1, 1, 0};
int dy[8] = {-1, 0, 1,1,1,0,-1,-1};

const int N = 1000 * 100 + 10;
vector<int> ans(N * 4, 0);

int query (int x, int y, int id, int l, int r) {
  if (l >= y || x >= r) return INT_MAX;
  if (x <= l && r <= y) return ans[id];

  int mid = (l + r) / 2;
  int a = query (x, y, 2 * id, l, mid);
  int b = query (x, y, 2 * id + 1, mid, r);

  return min(a, b);
}

void init (int id, int l, int r, vector<int> &v) {
  if (r - l < 2) {
    ans[id] = v[l];
    return;
  }

  int mid = (r + l) / 2;
  init (2 * id, l, mid, v);
  init (2 * id + 1, mid, r, v);

  ans[id] = min(ans[2 * id], ans[2 * id + 1]);
}

int main() {
  int t;
  cin >> t;

  int TC = 1;
  while (t --> 0) {
    int n, q;
    scanf("%d %d", &n, &q);

    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];

    init (1, 0, n, v);

    printf("Case %d:\n", TC ++);
    for (int i = 0; i < q; ++i) {
      int l, r;
      scanf("%d %d", &l, &r);
      printf("%d\n", query (l - 1, r, 1, 0, n));
    }
  }

  return 0;
}
