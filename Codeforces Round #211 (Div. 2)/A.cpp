// http://codeforces.com/contest/363/problem/A

#include<bits/stdc++.h>
using namespace std;

#define __ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define foreach(it, x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define all(x) x.begin(),x.end()
#define D(x) cout << #x " = " << (x) << endl;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

int dx[8] = {-1,-1,-1,0,1,1, 1, 0};
int dy[8] = {-1, 0, 1,1,1,0,-1,-1};

string f(int n) {
  if (n == 0) return "O-|-OOOO";
  if (n == 1) return "O-|O-OOO";
  if (n == 2) return "O-|OO-OO";
  if (n == 3) return "O-|OOO-O";
  if (n == 4) return "O-|OOOO-";
  if (n == 5) return "-O|-OOOO";
  if (n == 6) return "-O|O-OOO";
  if (n == 7) return "-O|OO-OO";
  if (n == 8) return "-O|OOO-O";
  if (n == 9) return "-O|OOOO-";
}

int main(){ __
  int n;
  cin >> n;

  if (!n) {
    cout << f(0) << endl;
    return 0;
  }

  while (n) {
    int d = n%10;
    cout << f(d) << endl;
    n /= 10;
  }
  return 0;
}