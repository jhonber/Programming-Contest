// http://codeforces.com/contest/322/problem/B

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
  int a,b,c;
  cin >> a >> b >> c;

  if ((a % 3 == 0 && b % 3 == 0 && c % 3 == 0) || (!a || !b || !c)) {
    cout << (a / 3) + (b / 3) + (c / 3);
  }
  else {
    int c1,c2,c3;
    if (a % 3 == 0) {
      c1 = (a - 3) / 3;
      a = 3;
    }
    else {
      c1 = a / 3;
      a = a % 3;
    }

    if (b % 3 == 0) {
      c2 = (b - 3) / 3;
      b = 3;
    }
    else {
      c2 = b / 3;
      b = b % 3;
    }

    if (c % 3 == 0) {
      c3 = (c - 3) / 3;
      c = 3;
    }
    else {
      c3 = c / 3;
      c = c % 3;
    }

    int res = max(min(a, min(b, c)), (a / 3) + (b / 3) + (c / 3));
    cout << c1 + c2 + c3 + res;
  }

  return 0;
}