// http://codeforces.com/contest/500/problem/B

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

void dfs (int i, vector<string> &mat, vector<int> &visited, vector<int> &v, set<int> &comp, set<int> &ind) {
  if (!visited[i]) {
    comp.insert(v[i]);
    ind.insert(i);
    visited[i] = true;
    for (int j = 0; j < mat.size(); ++j) if (mat[i][j] == '1') {
      dfs(j, mat, visited, v, comp, ind);
    }
  }
}

int main() {
  int n;
  cin >> n;

  vector<int> v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];

  vector<string> mat(n);
  for (int i = 0; i < n; ++i) cin >> mat[i];

  vector<int> ans = v;
  vector<int> visited(n, 0);
  for (int i = 0; i < n; ++i) {
    if (!visited[i]) {
      set<int> comp, ind;
      dfs (i, mat, visited, v, comp, ind);
      set<int> :: iterator it = comp.begin();
      foreach(x, ind) {
        ans[*x] = *it;
        it ++;
      }
    }
  }

  for (int i = 0; i < n; ++i) cout << ans[i] << " ";

  return 0;
}