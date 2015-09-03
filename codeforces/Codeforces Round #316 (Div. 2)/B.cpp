// http://codeforces.com/contest/570/problem/B

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
  int n, m;
  cin >> n >> m;

  if (n == 2) {
    if (m == 1) cout << 2;
    else cout << 1;
    return 0;
  }

  int ans1 = max(0, m - 2);
  int ans2 = max(0, n - (m + 1));

  if (ans1 >= ans2) cout << max(1, m - 1);
  else cout << min(m + 1, n);

  return 0;
}
