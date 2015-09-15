// http://codeforces.com/contest/388/problem/A

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
  int n;
  cin >> n;

  vector<int> v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];

  sort(all(v));
  reverse(all(v));

  for (int i = 1; i <= n; ++i) {
    vector<int> cur(i,10000);
    bool found = true;
    for (int j = 0; j < n; ++j) {
      int pos = j % i;
      int cap = cur[pos];
      if (cap <= 0) {
        found = false;
        break;
      }
      cur[pos] = min(cap - 1, v[j]);
    }
    if (found) {
      cout << i;
      return 0;
    }
  }

  return 0;
}