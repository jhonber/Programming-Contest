// http://codeforces.com/contest/570/problem/A

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
  int n, m;
  cin >> n >> m;

  vector< pair<int, int> > v[m];
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      int t;
      cin >> t;
      v[i].push_back(make_pair(t, j));
    }
  }

  vector< pair<int, int> > vv;
  vector<int> vvv(n,0);
  for (int i = 0; i < m; ++i) sort(all(v[i]));
  for (int i = 0; i < m; ++i) {
    int best = v[i][v[i].size() - 1].first;
    for (int j = 0; j < v[i].size(); ++j) {
      if (v[i][j].first == best) {
        vvv[v[i][j].second] ++;
        break;
      }
    }
  }

  int best = 0;
  for (int i = 0; i < n; ++i) best = max(best, vvv[i]);
  for (int i = 0; i < n; ++i) if (vvv[i] == best) {
    cout << i + 1;
    return 0;
  }

  return 0;
}
