// http://codeforces.com/contest/465/problem/B

#include<bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define foreach(it, x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define all(x) x.begin(),x.end()
#define D(x) cout << #x " = " << (x) << endl;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

int dx[8] = {-1,-1,-1,0,1,1, 1, 0};
int dy[8] = {-1, 0, 1,1,1,0,-1,-1};

int main(){ __
  int n;

  cin >> n;

  int v[n];
  int tot = 0;

  for (int i=0; i<n; ++i) {
    cin >> v[i];
    if (v[i])
      tot ++;
  }

  if (!tot) {
    cout << 0;
    return 0;
  }

  int ans = tot;
  for (int i=0; i<n;) {
    int f = false;
    while (v[i] && i<n) {
      f = true;
      i++;
    }
    while (!v[i] && i<n) i++;
    if (f && i<n && v[i])
      ans ++;
  }

  cout << ans;
  return 0;
}