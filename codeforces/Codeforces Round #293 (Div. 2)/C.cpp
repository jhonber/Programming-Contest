// http://codeforces.com/contest/518/problem/C

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
  int n,m,k;
  cin >> n >> m >> k;

  map<int,int> pos;
  map<int,int> pos2;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
    pos[v[i]] = i;
    pos2[i] = v[i];
  }

  long long ans = 0;
  int q;
  for (int i = 0; i < m; ++i) {
    cin >> q;
    double t = (double)pos[q] / (double)k;
    if (t < 1) ans ++;
    else ans += ((int)t) + 1;
    if (t != 0.0) {
      int p = pos[q];
      int val = pos2[p - 1];
      pos2[p - 1] = q;
      pos2[p] = val;
      pos[q] = p - 1;
      pos[val] = p;
    }
  }

  cout << ans;

  return 0;
}