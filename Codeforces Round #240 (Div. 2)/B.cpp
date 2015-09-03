// http://codeforces.com/contest/415/problem/B

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
  int n;
  long long a,b;
  cin >> n >> a >> b;

  vector<int> v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];

  for (int i = 0; i < n; ++i) {
    long long mmax = (v[i] * a) / b;
    long long w = ceil(((double)(b * mmax)) / a);
    cout << " " << v[i] - w;
  }

  return 0;
}