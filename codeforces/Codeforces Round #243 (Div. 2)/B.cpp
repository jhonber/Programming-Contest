// http://codeforces.com/contest/426/problem/B

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

  if (n % 2 != 0) {
    cout << n;
    return 0;
  }

  vector<string> v(n);
  for (int i = 0; i < n; ++i) {
    string s;
    for (int j = 0; j < m; ++j) {
      string t;
      cin >> t;
      s += t;
    }
    v[i] = s;
  }

  int mid = n;
  while (true) {
    if (mid % 2 != 0) break;
    for (int i = 0; i < mid; ++i) {
      if (v[i] != v[mid - i - 1]) {
        cout << mid;
        return 0;
      }
    }
    mid /= 2;
  }

  cout << mid;
  return 0;
}