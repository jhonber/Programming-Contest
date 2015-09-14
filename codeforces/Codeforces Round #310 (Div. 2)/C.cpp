// http://codeforces.com/contest/556/problem/C

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
  int n, k;
  cin >> n >> k;

  int tot = 0;
  int cnt = 1;
  vector<int> v[k];
  for (int i = 0; i < k; ++i) {
    int t;
    cin >> t;
    for (int j = 0; j < t; ++j) {
      int a;
      cin >> a;
      v[i].push_back(a);
    }
    if (v[i][0] == 1) {
      for (int j = 1; j < t; ++j) {
        if (v[i][j - 1] + 1 == v[i][j]) cnt ++;
        else break;
      }
      tot += (t - cnt) ;
    }
    else tot += t - 1;
  }

  cout << tot + (n - cnt);
  return 0;
}