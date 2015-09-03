// http://codeforces.com/contest/479/problem/D

#include<bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define foreach(it, x) for (__typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define all(x) x.begin(),x.end()
#define D(x) cout << #x " = " << (x) << endl;

template <class t> string tostr(const t &x)
{ stringstream s; s << x; return s.str(); }

template <class t> int toint(const t &x)
{ stringstream s; s << x; int r; s >> r; return r; }

int dx[8] = {-1,-1,-1,0,1,1, 1, 0};
int dy[8] = {-1, 0, 1,1,1,0,-1,-1};

int main(){ __
  int n,l,x,y;
  cin >> n >> l >> x >> y;

  map<int,int> mapa;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
    mapa[v[i]] ++;
  }

  int f1 = false;
  int f2 = false;

  for (int i = 0; i < n - 1; ++i) {
    int d = v[i] + x;
    if (d > l || f1) break;
    if (mapa.find(d) != mapa.end()) f1 = true;
  }

  for (int i = 0; i < n - 1; ++i) {
    int d = v[i] + y;
    if (d > l || f2) break;
    if (mapa.find(d) != mapa.end()) f2 = true;
  }

  if (f1 && f2) cout << 0;
  else if (f1 && !f2) cout << 1 << endl << y;
  else if (!f1 && f2) cout << 1 << endl << x;
  else {
    for (int i = 0; i < n - 1; ++i) {
      int d = v[i] + x;
      int d2 = v[i] - x;

      if ((mapa.find(d + y) != mapa.end() || mapa.find(d - y) != mapa.end()) && d < l && d > 0) {
        cout << 1 << endl << d;
        return 0;
      }
      if ((mapa.find(d2 + y) != mapa.end() || mapa.find(d2 - y) != mapa.end()) && d2 < l && d2 > 0) {
        cout << 1 << endl << d2;
        return 0;
      }
    }

    for (int i = 0; i < n - 1; ++i) {
      int d = v[i] + y;
      int d2 = v[i] - y;

      if ((mapa.find(d + x) != mapa.end() || mapa.find(d - x) != mapa.end()) && d < l && d > 0) {
        cout << 1 << endl << d;
        return 0;
      }
      if ((mapa.find(d2 + x) != mapa.end() || mapa.find(d2 - x) != mapa.end()) && d2 < l && d2 > 0) {
        cout << 1 << endl << d2;
        return 0;
      }
    }

    cout << 2 << endl << x << " " << y;
  }

  return 0;
}