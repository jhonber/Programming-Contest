// http://codeforces.com/contest/227/problem/B

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

int main(){ __
  int n,q;
  cin >> n;

  int t;
  map<int,int> mapa;
  for (int i = 0; i < n; ++i) {
    cin >> t;
    mapa[t] = i;
  }

  long long p1 = 0, p2 = 0;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    cin >> t;
    p1 += mapa[t] + 1;
    p2 += n - mapa[t];
  }

  cout << p1 << " " << p2;

  return 0;
}