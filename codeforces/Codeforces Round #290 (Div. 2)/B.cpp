// http://codeforces.com/contest/510/problem/B

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

char mat[55][55];
map< pair<int,int>,int > color;

int size,f,n,m;

bool check(int a, int b) {
  if (a >= 0 && b >= 0 && a < n && b < m) return true;
  return false;
}

void dfs(pair<int,int> i, pair<int,int> j) {
  if (!color[i]) {
    color[i] = true;
    size ++;
    char c = mat[i.first][i.second];
    for (int x = 1; x < 8; x += 2) {
      int a = i.first + dx[x];
      int b = i.second + dy[x];
      if (check(a,b) and mat[a][b] == c and !(a == j.first and b == j.second)) {
        if (color[make_pair(a,b)]) {
          f = true;
        }
        dfs(make_pair(a,b),i);
      }
    }
  }
}

int main() {
  cin >> n >> m;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> mat[i][j];
    }
  }


  int ans = false;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      pair<int,int> p = make_pair(i,j);
      if (!color[p]) {
        size = 0; f = false;
        dfs(p,make_pair(-1,-1));
        if (f && size >= 4) ans = true;
      }
    }
  }

  cout << (ans ? "Yes" : "No");

  return 0;
}