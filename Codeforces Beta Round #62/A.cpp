// http://codeforces.com/contest/68/problem/A

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
  int a,b;
  vector<int> v(4), vv;
  cin >> v[0] >> v[1] >> v[2] >> v[3] >> a >> b;

  sort(all(v));
  vv = v;
  int ans = 0;
  while (a <= b) {
    int cnt = 0;
    int tot = 0;
    do {
      int rez = (((a % v[0]) % v[1]) % v[2]) % v[3];
      if (rez == a) cnt ++;
      tot ++;
    }
    while ( next_permutation( all(v) ) );
    if (cnt >= 7) ans ++;
    v = vv;
    a ++;
  }

  cout << ans;
  return 0;
}