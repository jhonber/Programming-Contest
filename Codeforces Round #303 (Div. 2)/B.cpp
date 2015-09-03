// http://codeforces.com/contest/545/problem/B

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
  string s,t;
  cin >> s >> t;

  string p;
  int f = true;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == t[i]) p += toStr(s[i]);
    else {
      if (f) {
        p += toStr(s[i]);
        f = !f;
      }
      else {
        p += toStr(t[i]);
        f = !f;
      }
    }
  }

  int dif1 = 0;
  int dif2 = 0;

  for (int i = 0; i < s.size(); ++i) {
    if (s[i] != p[i]) dif1 ++;
    if (t[i] != p[i]) dif2 ++;
  }

  if (dif1 == dif2) cout << p;
  else cout << "impossible";

  return 0;
}