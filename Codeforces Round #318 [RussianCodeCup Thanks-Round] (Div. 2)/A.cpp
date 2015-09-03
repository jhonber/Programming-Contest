// http://codeforces.com/contest/574/problem/A

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
  int n,t;
  cin >> n;

  cin >> t;
  int a = t;
  int ans = 0;

  vector<int> v(n - 1);
  for (int i = 0; i < n - 1; ++i) cin >> v[i];

  while (true) {
    int last = v.size() - 1;
    sort(all(v));
    if (v[last] < a) break;
    if (v[last] <= 0) break;
    a ++;
    v[last] --;
    ans ++;
  }

  cout << ans;

  return 0;
}