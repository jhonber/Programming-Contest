// http://codeforces.com/contest/12/problem/C

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
  int n,m;
  cin >> n >> m;

  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }

  map<string,int> mapa;
  for (int i = 0; i < m; ++i) {
    string s;
    cin >> s;
    mapa[s] ++;
  }

  sort(all(v));

  vector<int> tmp;
  int ans1 = 0, ans2 = 0;
  foreach(x,mapa) {
    int t = x->second;
    tmp.push_back(t);
  }

  sort(all(tmp));

  int i = 0;
  for (int j = tmp.size() - 1; j >= 0; --j, ++i) {
    ans1 += (tmp[j] * v[i]);
  }

  int k = n - 1;
  for (int j = tmp.size() - 1; j >= 0 ; --j, --k) {
    ans2 += (tmp[j] * v[k]);
  }

  cout << ans1 << " " << ans2;

  return 0;
}