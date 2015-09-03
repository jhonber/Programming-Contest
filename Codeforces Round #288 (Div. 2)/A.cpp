// http://codeforces.com/contest/508/problem/A

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

int n,m;
int mat[1111][1111];

bool check(int a, int b) {
  int f = true;
  for (int i = 1; i < 4; ++i) if (mat[a + dx[i]][b + dy[i]] == 0) f = false;
  if (f) return f;
  f = true;
  for (int i = 3; i < 6; ++i) if (mat[a + dx[i]][b + dy[i]] == 0) f = false;
  if (f) return f;
  f = true;
  for (int i = 5; i < 8; ++i) if (mat[a + dx[i]][b + dy[i]] == 0) f = false;
  if (f) return f;
  f = true;
  for (int i = 0; i < 2; ++i) if (mat[a + dx[i]][b + dy[i]] == 0) f = false;
  if (mat[a + dx[7]][b + dy[7]] == 0) f = false;
  return f;
}

int main() { __
  int k;
  cin >> n >> m >> k;

  memset(mat,0,sizeof mat);

  int ans = 0;
  int a,b;
  for (int i = 0; i < k; ++i) {
    cin >> a >> b;
    mat[a][b] = true;
    if (!ans && check(a,b))
      ans = i + 1;
  }

  cout << ans;
  return 0;
}