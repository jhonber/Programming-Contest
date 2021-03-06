// http://codeforces.com/contest/490/problem/A

#include<bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define foreach(it, x) for (__typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define all(x) x.begin(),x.end()
#define d(x) cout << #x " = " << (x) << endl;

template <class t> string tostr(const t &x)
{ stringstream s; s << x; return s.str(); }

template <class t> int toint(const t &x)
{ stringstream s; s << x; int r; s >> r; return r; }

int dx[8] = {-1,-1,-1,0,1,1, 1, 0};
int dy[8] = {-1, 0, 1,1,1,0,-1,-1};

int main(){ __
  int n;
  cin >> n;

  vector<int> v[3];
  for (int i = 0; i < n; ++i) {
    int t;
    cin >> t;
    v[t - 1].push_back(i + 1);
  }

  int s = min(v[0].size(),min(v[1].size(),v[2].size()));
  cout << s << endl;

  for (int i = 0; i < s; ++i)
    cout << v[0][i] << " " << v[1][i] << " " << v[2][i] << endl;

  return 0;
}