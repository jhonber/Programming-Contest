// http://codeforces.com/contest/476/problem/A

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

int main(){ __
  int n,m;
  cin >> n >> m;

  int ans = INT_MAX;
  for (int y = 0; y <= n; ++y) {
    int x = n - (2 * y);
    if (x + (2 * y) == n && (x + y) % m == 0 && x >= 0 && y >= 0)
      ans = min(ans, x + y);
  }

  cout << (ans == INT_MAX ? -1 : ans);

  return 0;
}