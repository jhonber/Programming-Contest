// http://codeforces.com/contest/514/problem/A

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
  string x;
  cin >> x;

  string ans;
  for (int i = 0; i < x.size(); ++i) {
    int t = 9 - toInt(x[i]);
    if ((t > 0 && t < toInt(x[i])) || !t && i > 0) ans += toStr(t);
    else ans += toStr(x[i]);
  }

  cout << ans;
  return 0;
}