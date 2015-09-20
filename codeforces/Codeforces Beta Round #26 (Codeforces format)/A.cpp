// codeforces.com/problemset/problem/26/A

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

bool is_prime(int x) {
  if (x == 2) return true;
  int i = 2;
  while (i * i <= x) {
    if (x % i == 0) return false;
    i ++;
  }
  return true;
}

int cnt_div(int x) {
  int div = 0;
  for (int i = 2; i <= x; ++i) if (x % i == 0 && is_prime(i)) div ++;
  return div;
}

int main() {
  int n;
  cin >> n;

  int ans = 0;
  for (int i = 1; i <= n; ++i) if (cnt_div(i) == 2) ans ++;
  cout << ans;

  return 0;
}
