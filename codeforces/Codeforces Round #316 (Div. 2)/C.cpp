// http://codeforces.com/contest/570/problem/C

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
  int n, m;
  cin >> n >> m;

  string s;
  cin >> s;

  s = "*" + s + "*";

  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (s[i] == '.' and i < n and s[i + 1] == '.') ans ++;
    if (s[i] != '.') s[i] = 'x';
  }

  for (int i = 0; i < m; ++i) {
    int p; char c;
    cin >> p >> c;

    string ss = s.substr(p - 1, 3);

    if (c != '.' and s[p] == '.') {
      if (ss == "..x" or ss == "x.." or ss == "..*" or ss == "*..") ans --;
      else if (ss == "...") ans -= 2;
    }
    else if (c == '.' and s[p] != '.') {
      if (ss == ".x.") ans += 2;
      else if (ss == ".xx" or ss == "xx." or ss == "*x." or ss == ".x*") ans ++;
    }

    c = c != '.' ? 'x' : '.';
    s[p] = c;
    cout << ans << endl;
  }

  return 0;
}
