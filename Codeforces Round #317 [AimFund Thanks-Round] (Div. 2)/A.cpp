// http://codeforces.com/contest/572/problem/A

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
  int a,b,k,m;
  cin >> a >> b >> k >> m;

  vector<int> v(a),vv(b);
  for (int i = 0; i < a; ++i) {
    cin >> v[i];
  }

  for (int i = 0; i < b; ++i) {
    cin >> vv[i];
  }

  int num = v[k - 1];
  vector<int> :: iterator upp = upper_bound(all(vv), num);

  int s = b - (upp - vv.begin());
  if (s >= m) cout << "YES";
  else cout << "NO";

  return 0;
}