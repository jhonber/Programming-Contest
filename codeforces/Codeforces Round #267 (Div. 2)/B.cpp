// http://codeforces.com/contest/467/problem/B

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
  int n,m,k;
  cin >> n >> m >> k;

  vector< bitset<22> > v(m);
  for (int i=0; i<m; ++i) {
    int t;
    cin >> t;
    v[i] = t;
  }

  int last;
  cin >> last;

  int ans = 0;
  bitset<22> tmp = last;
  string tt = tmp.to_string();
  for (int i=0; i<m; ++i) {
    string t = v[i].to_string();
    int cont = 0;
    for (int x=0; x<22; ++x) {
      if (t[x] != tt[x])
        cont++;
    }
    if (cont <= k)
      ans ++;
  }

  cout << ans;

  return 0;
}