// http://codeforces.com/contest/267/problem/A

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

int solve(int a, int b) {
  if (a == b) return 1;
  if (min(a,b) * 2 == max(a,b)) return 2;
  if (abs(a - b) == 1) return max(a,b);

  int ans = 0;
  while (a != 1 and b != 1) {
    if (a == b) {
      ans ++;
      return ans;
    }

    int mmin = min(a, b);
    int mmax = max(a, b);
    int x = ceil( ((double)mmax - mmin) / mmin );
    ans += x;
    mmax -= mmin * x;

    if ((min(mmax, mmin) * 2) == max(mmin, mmax)) return ans + 2;
    if (abs(mmax - mmin) == 1) return ans + mmin;
    if (mmin == mmax) return ans + 1;
    a = mmin;
    b = mmax;
  }
  ans += max(a, b);
  return ans;
}

int main() {
  int n, a, b;
  cin >> n;

  while (n --> 0) {
    cin >> a >> b;
    cout << solve(a,b) << endl;
  }

  return 0;
}