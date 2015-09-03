// http://codeforces.com/contest/475/problem/B

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
map< pair<int,int> , int > visited;
map< pair<int,int> , char > mat1;
map< pair<int,int> , char > mat2;

int n,m;

bool check(pair<int,int> k) {
  int i = k.first, j = k.second;
  if (i >= 0 && i < n && j >= 0 && j < m)
    return true;
  return false;
}

void dfs(pair<int,int> i) {
  if (!check(i)) return;
  if (!visited[i]) {
    visited[i] = true;
    if ( mat1[i] == '>' )
      dfs(make_pair(i.first, i.second + 1));

    if ( mat1[i] == '<' )
      dfs(make_pair(i.first, i.second - 1));

    if ( mat2[i] == 'v' )
      dfs(make_pair(i.first + 1, i.second));

    if ( mat2[i] == '^' )
      dfs(make_pair(i.first - 1, i.second));
  }
}

int main() { __
  cin >> n >> m;

  char c;
  for (int i = 0; i < n; ++i) {
    cin >> c;
    for (int j = 0; j < m; ++j) {
      mat1[make_pair(i,j)] = c;
    }
  }

  for (int i = 0; i < m; ++i) {
    cin >> c;
    for (int j = 0; j < n; ++j) {
      mat2[make_pair(j,i)] = c;
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      visited.clear();
      dfs( make_pair(i,j) );

      if (visited.size() != n * m) {
        cout << "NO";
        return 0;
      }
    }
  }

  cout << "YES";
  return 0;
}