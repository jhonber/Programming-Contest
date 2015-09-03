// http://codeforces.com/contest/63/problem/B

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
  int n,k;
  cin >> n >> k;

  int v[222],t;
  memset(v,0,sizeof v);

  for (int i=0; i<n; ++i) {
    cin >> t;
    v[t] ++;
  }

  int ans = 0;
  while (true) {
    int f = true;
    int vv[222];
    memset(vv,0,sizeof vv);

    for (int i=1; i<=100 && v[k] != n; ++i) {
      if (v[i] && i != k) {
        v[i] --;
        vv[i+1] ++;
        f = false;
      }
    }

    for (int i=1; i<=100; ++i)
      v[i] += vv[i];

    if (!f)
      ans ++;
    else break;
  }

  cout << ans;

  return 0;
}