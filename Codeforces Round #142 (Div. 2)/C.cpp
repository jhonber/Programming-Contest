// http://codeforces.com/contest/230/problem/C

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
  int n,m;
  cin >> n >> m;

  int mat1[111][11111], mat2[111][11111];
  memset(mat1, 0, sizeof mat1);
  memset(mat2, 0, sizeof mat2);

  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;

    if (s.find('1') == string::npos) {
      cout << -1;
      return 0;
    }

    for (int j = 0; j < m; ++j) {
      if (s[j] == '1') {
        int k = j, cnt = 1;
        while (true) {
          k --;
          if (k < 0) k = m - 1;
          if (s[k] == '1') break;
          mat1[i][k] = cnt ++;
        }

        cnt = 1; k = j;
        while (true) {
          k ++;
          if (s[k % m] == '1') break;
          mat2[i][k % m] = cnt ++;
        }
      }
    }
  }


  int ans = INT_MAX;
  for (int i = 0; i < m; ++i) {
    int tot = 0;
    for (int j = 0; j < n; ++j) tot += min(mat1[j][i], mat2[j][i]);
    ans = min(ans, tot);
  }

  cout << (ans == INT_MAX ? -1 : ans);
  return 0;
}