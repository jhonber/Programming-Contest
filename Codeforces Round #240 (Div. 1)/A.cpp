// http://codeforces.com/contest/414/problem/A

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

int main() { __
  int n,k;
  cin >> n >> k;

  if (n == 1) {
    if (!k) cout << 1;
    else cout << -1;
    return 0;
  }

  if (k < n / 2) cout << -1;
  else {
    int tot = n / 2;
    k -= tot - 1;
    int j = k * 2 + 1;
    cout << k << " " << k * 2;
    for (int i = 0; i < tot - 1; ++i, j += 2) cout << " " << j << " " << j + 1;
    if (n % 2 != 0) cout << " " << j + 1;
  }

  return 0;
}