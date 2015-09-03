// http://codeforces.com/contest/248/problem/B

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
  int n;
  cin >> n;

  if (n <= 3) {
    if (n < 3) cout << -1;
    else cout << 210;

    return 0;
  }

  vector<string> v = {"5", "8", "17", "2", "20", "11"};
  int op = (n - 4)  % 6;
  string sufix = v[op];
  string zeros;

  n -= (2 + sufix.size());
  while (n --> 0) zeros += "0";

  cout << "1" + zeros + sufix + "0";
  return 0;
}