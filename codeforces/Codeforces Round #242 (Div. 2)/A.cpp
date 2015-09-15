// http://codeforces.com/contest/424/problem/A

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
  int n;
  cin >> n;

  string s;
  cin >> s;

  int up = 0;
  for (int i = 0; i < n; ++i) if (s[i] == 'X') up ++;

  int ans;

  if (up >= n / 2) {
    int cnt = up - (n / 2);
    ans = cnt;
    for (int i = 0; cnt > 0 ; i++) if (s[i] == 'X') {
      s[i] = 'x';
      cnt --;
    }
  }
  else {
    int cnt = (n / 2) - up;
    ans = cnt;
    for (int i = 0; cnt > 0 ; i++) if (s[i] == 'x') {
      s[i] = 'X';
      cnt --;
    }
  }

  cout << ans << endl << s;

  return 0;
}