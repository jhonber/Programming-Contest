// http://codeforces.com/contest/558/problem/B

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
  int n;
  cin >> n;

  map<int,int> mapa1, mapa2;
  vector<int> v(n);

  int init = 0;
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
    mapa1[v[i]] ++;
  }

  foreach (x, mapa1) {
    init = max(x->second, init);
  }

  set<int> ready;
  map<int, int> pos;
  for (int i = n - 1; i >= 0; --i) {
    if (ready.count(v[i]) == 0) {
      ready.insert(v[i]);
      pos[v[i]] = i;
    }
  }

  int l, r;
  int best = INT_MAX;

  for (int i = 0; i < n; ++i) {
    mapa2[v[i]] ++;
    int p = pos[v[i]];
    int d = (p - i) + 1;
    int cnt = mapa1[v[i]] - (mapa2[v[i]] - 1);

    if (d < best and cnt == init) {
      best = d;
      l = i; r = p;
    }
  }

  cout << l + 1 << " " << r + 1;
  return 0;
}