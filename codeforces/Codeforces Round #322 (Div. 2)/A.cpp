// http://codeforces.com/contest/581/problem/A

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
  int a, b;
  cin >> a >> b;

  int ans1 = 0;
  while (true) {
    if (a - 1 >= 0 && b - 1 >= 0) {
      ans1 ++;
      a --;
      b --;
    }
    else break;
  }

  cout << ans1 << " " << max(a / 2, b / 2);
  return 0;
}