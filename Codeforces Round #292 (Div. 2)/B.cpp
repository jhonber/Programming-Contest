// http://codeforces.com/contest/515/problem/B

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
  int n,m,aaa,bbb;

  cin >> n >> m;

  vector<int> b(n), g(m);
  cin >> aaa;
  for (int i = 0; i < aaa; ++i) {
    int t;
    cin >> t;
    b[t] = true;
  }

 cin >> bbb;
  for (int i = 0; i < bbb; ++i) {
    int t;
    cin >> t;
    g[t] = true;
  }

  for (int i = 0; i < 10000; ++i) {
    int aa = b[i % n];
    int bb = g[i % m];

    if (aa + bb >= 1) {
      b[i % n] = g[i % m] = true;
    }
  }

  int tot = 0;
  for (int i = 0; i < n; ++i) tot += b[i];
  for (int i = 0; i < m; ++i) tot += g[i];


  if (tot == n + m) cout << "Yes";
  else cout << "No";

  return 0;
}