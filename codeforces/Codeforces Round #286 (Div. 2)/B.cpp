// http://codeforces.com/contest/505/problem/B

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

vector<int> G[111];
map< pair<int,int>, set<int> > color;
int visited[111];
int flag;

void dfs(int i, int j, int c) {
  if (i == j) flag = true;
  if (!visited[i]) {
    visited[i] = true;
    for (int x = 0; x < G[i].size(); ++x) {
      if ( color[make_pair(i,G[i][x])].count(c) ) dfs(G[i][x],j,c);
    }
  }
}

int main() { __
  int v,e,q;
  cin >> v >> e;
  int a,b,c;
  for (int i = 0; i < e; ++i) {
    cin >> a >> b >> c; a--; b--; c--;
    G[a].push_back(b);
    G[b].push_back(a);
    color[make_pair(a,b)].insert(c);
    color[make_pair(b,a)].insert(c);
  }

  cin >> q;
  for (int i = 0; i < q; ++i) {
    cin >> a >> b; a--; b--;
    int ans = 0;
    for (int j = 0; j < e; ++j) {
      flag = false;
      memset(visited,0,sizeof visited);
      dfs(a,b,j);
      ans += flag;
    }
    cout << endl;
    cout << ans << endl;
  }

  return 0;
}