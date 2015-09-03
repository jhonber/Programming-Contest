// http://codeforces.com/contest/445/problem/B

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

vector<int> visited(100,0);
vector<int> G[100];

int dfs(int i) {
  if (visited[i]) return 0;
  stack<int> Q;
  Q.push(i);
  visited[i] = true;

  while(!Q.empty()) {
    int v = Q.top(); Q.pop();

    for (int x=0; x<G[v].size(); ++x) {
      if (!visited[G[v][x]]) {
        visited[G[v][x]] = true;
        Q.push(G[v][x]);
      }
    }
  }

  return true;
}

int main(){ __
  int n,m,a,b;
  cin >> n >> m;

  for (int i=0; i<m; ++i) {
    cin >> a >> b; a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  int c = 0;
  for (int i=0; i<n; ++i)
    c += dfs(i);

  c = n-c;
  long long ans = 1;
  while ( c --> 0)
    ans *= 2;

  cout << ans;
  return 0;
}