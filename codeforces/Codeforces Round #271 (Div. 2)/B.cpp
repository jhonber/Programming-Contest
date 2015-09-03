// http://codeforces.com/contest/474/problem/B

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
  int n,m;
  cin >> n;

  vector<int> v(n);
  v[0] = 0;
  for (int i = 1; i <= n; ++i) {
    int a;
    cin >> a;
    v[i] = v[i-1] + a;
  }

  cin >> m;
  int b;
  vector<int> :: iterator it;
  for (int i = 0; i < m; ++i) {
    cin >> b;
    it = lower_bound(all(v),b);
    cout << (it- v.begin()) << endl;
  }

  return 0;
}