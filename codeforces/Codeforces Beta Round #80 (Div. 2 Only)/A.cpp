// http://codeforces.com/contest/104/problem/A

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
  vector<int> v = {1,2,3,4,5,6,7,8,9,10,10,10,10};

  int n;
  cin >> n;

  int ans = 0;
  int tot = 10;

  if (tot + 1 == n or tot + 11 == n) ans += 4;

  for (int i = 1; i < v.size(); ++i) {
    if (tot + v[i] == n) {
      if (i == 11) ans += 3;
      else ans += 4;
    }
  }

  cout << ans;
  return 0;
}