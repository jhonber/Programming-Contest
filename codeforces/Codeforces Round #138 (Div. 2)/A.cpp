// http://codeforces.com/contest/224/problem/A

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
  int a1, a2, a3;
  cin >> a1 >> a2 >> a3;

  int mx = 1000000;
  int a,b,c;
  for (int i = 0; i < mx; ++i) {
    a = max(i, 1);
    b = max(a1 / a, 1);
    c = max(a3 / b, 1);
    if (a * b == a1 and a * c == a2 and b * c == a3) {
      cout << (4 * a) + (4 * b) + (4 * c);
      return 0;
    }
  }

  return 0;
}