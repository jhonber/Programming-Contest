// http://codeforces.com/contest/433/problem/B

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

int main() {
  int n,m,op;
  cin >> n;

  vector<int> v(n),vv;
  for (int i = 0; i < n; ++i) cin >> v[i];

  vv = v;
  sort(all(vv));

  long long img1[n + 1];
  long long img2[n + 1];

  img1[0] = img2[0] = 0;
  for (int i = 1; i <= n; ++i) img1[i] = img1[i - 1] + v[i - 1];
  for (int i = 1; i <= n; ++i) img2[i] = img2[i - 1] + vv[i - 1];

  int a,b;
  cin >> m;
  for (int i = 0; i < m; ++i) {
    cin >> op >> a >> b;
    if (op == 1) {
      cout << img1[b] - img1[a - 1] << endl;
    }
    else {
      cout << img2[b] - img2[a - 1] << endl;
    }
  }

  return 0;
}