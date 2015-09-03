// http://codeforces.com/contest/260/problem/A

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
  int a, b, n;
  cin >> a >> b >> n;

  for (int i = 0; i < 10; ++i) {
    if ((a * 10 + i) % b == 0) {
      cout << a * 10 + i;
      for (int i = 1; i < n; ++i) cout << 0;
      return 0;
    }
  }

  cout << -1;
  return 0;
}