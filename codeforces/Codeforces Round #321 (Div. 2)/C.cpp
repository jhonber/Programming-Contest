// http://codeforces.com/contest/580/problem/C

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

const int MX = 100000 + 100;

int n,m;
int ans = 0;
vector< int > G[MX];
vector<int> vcats(MX, 0);
vector<int> visited(MX, 0);

void dfs (int i, int cats) {
  if (!visited[i]) {
    visited[i] = true;
    if (i != 1 && cats <= m && G[i].size() == 1) ans ++;
    if (!vcats[i]) cats = 0;
    if (cats > m) return;

    for (int j = 0; j < G[i].size(); ++j) {
      dfs(G[i][j], cats + vcats[G[i][j]]);
    }
  }
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> vcats[i];

  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  dfs(1, vcats[1]);
  cout << ans;

  return 0;
}