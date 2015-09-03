// http://codeforces.com/contest/496/problem/C

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
bool check(vector<string> *good) {
  for (int i = 1; i < n; ++i) {
    if (good[i - 1] > good[i]) {
      for (int j = 0; j < n; ++j) good[j].pop_back();
      return false;
    }
  }
  return true;
}

int main() {
  cin >> n >> m;

  char mat[n][m];
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> mat[i][j];
    }
  }

  vector<string> tmp[n];
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      tmp[i].push_back( toStr(mat[i][j]) );
    }
  }

  if (check(tmp)) {
    cout << 0;
    return 0;
  }

  int one, two;
  int ans = m;
  one = 0;
  for (int i = 0; i < m; ++i) {
    vector<string> good[n];
    for (int x = 0; x < n; ++x) good[x].push_back( toStr(mat[x][i]) );
    if (check(good)) one ++;
    else continue;

    two = 0;
    for (int j = i + 1; j < m; ++j) {
      for (int x = 0; x < n; ++x) good[x].push_back( toStr(mat[x][j]) );
      if (check(good)) two ++;
      else continue;
    }
    ans = min(ans, m - (one + two));
  }

  cout << ans;
  return 0;
}