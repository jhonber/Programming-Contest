// http://codeforces.com/contest/459/problem/B

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
  int n;
  cin >> n;

  map<long long, int> v;

  long long mmax = -1;
  long long mmin = 10e10;
  for (int i=0; i<n; ++i) {
    long long t;
    cin >> t;
    v[t] ++;
    mmax = max(mmax, t);
    mmin = min(mmin, t);
  }

  if(mmax == mmin) {
    cout << 0 << " " << ((n-1LL) * n) / 2 << endl;
    return 0;
  }

  long long maxdif = mmax - mmin;
  cout << maxdif << " " << (v[mmin] + 0LL) * v[mmax] << endl;
  return 0;
}