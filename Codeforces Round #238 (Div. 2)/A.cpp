// http://codeforces.com/contest/405/problem/A

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

int main(){ __
  int n,a;
  cin >> n;

  int v[n];
  for (int i = 0; i < n; ++i) cin >> v[i];

  int f = *max_element(v,v + n);
  int mat[f][n];
  memset(mat, 0, sizeof mat);

  for (int i = 0; i < n; ++i) {
    for (int j = f - 1; j >= 0 && v[i]-- > 0; --j)
      mat[j][i] = true;
  }

  for (int i = f - 1; i >= 0; --i) {
    for (int j = n - 1; j >= 0; --j) {
      if (mat[i][j]) {
        int k = j + 1;
        while (mat[i][k] != true && k < n) {
          swap(mat[i][k - 1], mat[i][k]);
          k ++;
        }
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    int ai = 0;
    for (int j = 0; j < f; ++j)
      ai += mat[j][i];
    cout << ai << " ";
  }


  return 0;
}