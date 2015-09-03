// http://codeforces.com/contest/526/problem/B

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
  int n;
  cin >> n;
  int tot = (1 << (n + 1)) - 2;
  vector<int> v(tot + 1,0);
  for (int i = 0; i < tot; ++i) cin >> v[i];

  int ans = 0;
  vector<int> magic(tot,0);
  for (int i = 1 << (n - 1); i >= 1; i /= 2) {
    for (int j = i; j < i * 2; ++j) {
      if (j > 1)
        v[j - 2] += max(v[(j * 2) - 2], v[(j * 2 + 1) - 2]);
      ans += abs(v[(j * 2) - 2] - v[(j * 2 + 1) - 2]);
    }
  }

  cout << ans;
  return 0;
}