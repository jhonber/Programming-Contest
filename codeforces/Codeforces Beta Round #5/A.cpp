// http://codeforces.com/problemset/problem/5/A

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
  string s;
  int cur = 0;
  int ans = 0;
  while (getline(cin, s)) {
    if (s[0] == '+') cur ++ ;
    else if (s[0] == '-') cur --;
    else {
      stringstream ss;
      ss << s;
      string msj;
      while (getline(ss, msj, ':'));
      ans += msj.size() * cur;
    }
  }

  cout << ans;
  return 0;
}
