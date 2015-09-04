// http://codeforces.com/contest/574/problem/B

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

const int mx = 4004;
bool mat[mx][mx];

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> count(n, 0);
  int a,b;
  for (int i = 0; i < m; ++i) {
    cin >> a >> b; a --; b--;
    mat[a][b] = mat[b][a] = true;
    count[a] ++;
    count[b] ++;
  }

  int ans = INT_MAX;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (mat[i][j]) {
        for (int k = 0; k < n; ++k) {
          if (k != i and mat[j][k] and mat[k][i])
            ans = min(ans, (count[i] + count[j] + count[k]) - 6);
        }
      }
    }
  }

  cout << (ans == INT_MAX ? -1 : ans);

  return 0;
}