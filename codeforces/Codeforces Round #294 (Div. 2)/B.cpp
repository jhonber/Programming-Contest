// http://codeforces.com/contest/519/problem/B

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

  map<int,int> v;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    v[a] ++;
  }

  map<int,int> vv;
  for (int i = 1; i < n; ++i) {
    int a;
    cin >> a;
    vv[a] ++;
  }

  map<int,int> vvv;
  for (int i = 2; i < n; ++i) {
    int a;
    cin >> a;
    vvv[a] ++;
  }


  vector<int> ans;

  map<int,int> tmp = vv;
  foreach(x,v) {
    int veces = x->second;
    for (int i = 0; i < veces; ++i) {
      if (vv[x->first] == 0) {
        ans.push_back(x->first);
      }
      else vv[x->first] --;
    }
  }

  vv = tmp;
  foreach(x,vv) {
    int veces = x->second;
    for (int i = 0; i < veces; ++i) {
      if (vvv[x->first] == 0) {
        ans.push_back(x->first);
      }
      else vvv[x->first] --;
    }
  }
  cout << ans[0] << endl << ans[1];


  return 0;
}