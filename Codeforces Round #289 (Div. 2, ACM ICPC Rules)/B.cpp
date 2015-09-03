// http://codeforces.com/contest/509/problem/B

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
  int n,k;
  cin >> n >> k;

  vector<int> v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];

  vector<int> ans[n];
  for (int i = 0; i < n; ++i) {
    int tot = 0;
    while (tot < v[i]) {
      for (int j = 1; j <= k && tot < v[i]; ++j ) {
        ans[i].push_back(j);
        tot ++;
      }
    }
    sort(all(ans[i]));
  }

  int f = true;
  map<int,int> mapa1,mapa2;

  for (int i = 0; i < n; ++i) {
    for (int l = 0; l < ans[i].size(); ++l) mapa1[ans[i][l]] ++;
    for (int j = i + 1; j < n; ++j) {
      mapa2.clear();
      for (int l = 0; l < ans[j].size(); ++l) mapa2[ans[j][l]] ++;
      for (int l = 1; l <= k; ++l) {
        if (fabs(mapa1[l] - mapa2[l]) > 1) {
          cout << "NO";
          return 0;
        }
      }
    }
    mapa1.clear();
  }

  cout << "YES" << endl;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < ans[i].size(); ++j) cout << " " << ans[i][j];
    cout << endl;
  }

  return 0;
}