// http://codeforces.com/contest/25/problem/A

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

  vector< int > ans1, ans2;

  for (int i = 0; i < n; ++i) {
    int t;
    cin >> t;
    if (t % 2 == 0) ans1.push_back( i + 1 );
    else ans2.push_back( i + 1 );
  }

  if (ans1.size() == 1) cout << ans1[0];
  else cout << ans2[0];

  return 0;
}