// http://codeforces.com/contest/262/problem/C

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
  int m,n;
  cin >> m;

  vector<int> v(m);
  for (int i = 0; i < m; ++i) cin >> v[i];

  cin >> n;
  priority_queue<int> Q;
  for (int i = 0; i < n; ++i) {
    int t;
    cin >> t;
    Q.push(t);
  }

  sort(all(v));

  int ans = 0;
  while (!Q.empty()) {
    for (int i = 0; i < v[0] && Q.size() > 0; ++i) {
      int cur = Q.top(); Q.pop();
      ans += cur;
    }
    if (Q.size() > 0) Q.pop();
    if (Q.size() > 0) Q.pop();
  }

  cout << ans;
  return 0;
}