// http://codeforces.com/contest/507/problem/C

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
  long long h,n;
  cin >> h >> n; h++;

  int f = true;
  long long ans = 0;
  long long llevo = 0;
  while (h --> 0) {
    long long mid = (1LL << h) / 2 ;
    if (llevo + mid > n) {
      if(!f) ans += (mid * 2) - 1;
      f = false;
    }
    else if (llevo + mid < n) {
      if (h == 1) {
        if (f) ans += 2;
        else ans ++;
        break;
      }
      if (f) ans += (mid * 2) - 1;
      llevo += mid;
      f = true;
    }
    else {
      if (h == 1) {
        if (!f) ans += 2;
        else ans ++;
        break;
      }
      if (!f) ans += (mid * 2) - 1;
      f = false;
    }
    ans ++;
  }

  cout << ans;

  return 0;
}