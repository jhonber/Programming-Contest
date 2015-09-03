// http://codeforces.com/contest/346/problem/A

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
  int n,a,b;
  cin >> n >> a >> b;

  int mmax = max(a,b);
  int k = __gcd(a,b);

  for (int i = 2; i < n; ++i) {
    cin >> a;
    k = __gcd(k,a);
    mmax = max(mmax,a);
  }

  int tot = abs(n - (mmax / k));

  cout << (tot % 2 != 0 ? "Alice" : "Bob");

  return 0;
}