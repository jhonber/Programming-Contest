// http://codeforces.com/contest/463/problem/B

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
  vector<int> v;
  v.push_back(0);
  for (int i=0; i<n; ++i) {
    int t;
    cin >> t;
    v.push_back(t);
  }

  int ans = 0;
  int tt = 0;
  for (int i=1; i<n+1; ++i) {
    tt += (v[i-1] - v[i]);
    if (tt < 0) {
      ans += abs(tt);
      tt = 0;
    }
  }

  cout << ans;
  return 0;
}