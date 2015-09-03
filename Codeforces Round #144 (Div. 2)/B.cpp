// http://codeforces.com/contest/233/problem/B

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

long long s(long long x) {
  long long ans = 0;
  while (x) {
    ans += x%10;
    x /= 10;
  }
  return ans;
}

long long f(long long n, long long sx) {
  long long tmp = sqrt((sx*sx) + (4.0*n));
  long long x1 = (-sx + tmp) / 2.0;
  long long x2 = (-sx - tmp) / 2.0;

  if (x1 > 0) return x1;
  if (x2 > 0) return x2;
  return -1;
}

int main(){ __
  long long n;
  cin >> n;

  for (long long sx=1; sx<=81; ++sx) {
    long long x = f(n,sx);
    if ( x != -1 && ((x*x) + (s(x)*x) - n) == 0 ) {
      cout << x;
      return 0;
    }
  }

  cout << -1;
  return 0;
}