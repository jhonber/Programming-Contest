// http://codeforces.com/contest/426/problem/A

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
  int n,s;
  cin >> n >> s;

  int tot = 0;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
    tot += v[i];
  }

  for (int i = 0; i < n; ++i) {
    if (tot - v[i] <= s) {
      cout << "YES";
      return 0;
    }
  }
  cout << "NO";

  return 0;
}