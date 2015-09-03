// http://codeforces.com/contest/567/problem/A

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

int getDis(int a, int b) {
  if (a <= 0) {
    if (b <= 0) {
      return abs(a - b);
    }
    else {
      return abs(a) + b;
    }
  }
  else {
    if (a <= 0) {
      return abs(a - b);
    }
    else {
      return max(a,b) - min(a,b);
    }
  }
}

int main() {
  int n;
  cin >> n;

  vector<int> v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];

  for (int i = 0; i < n; ++i) {
    int mmax = -INT_MAX;
    int mmin = INT_MAX;

    if (i - 1 >= 0) mmin = min(getDis(v[i], v[i - 1]), mmin);
    if (i + 1 < n)  mmin = min(getDis(v[i], v[i + 1]), mmin);

    if (n - 1 != i) mmax = max(getDis(v[i], v[n - 1]), mmax);
    if (i != 0)     mmax = max(getDis(v[i], v[0]), mmax);

    cout << mmin << " " << mmax << endl;
  }

  return 0;
}