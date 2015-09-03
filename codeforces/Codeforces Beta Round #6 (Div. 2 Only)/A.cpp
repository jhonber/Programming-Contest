// http://codeforces.com/contest/6/problem/A

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
  vector<int> v(4);
  for (int i = 0; i < 4; ++i) cin >> v[i];

  sort(all(v));
  int f = false;
  do {
    vector<int> vv = v;
    sort(vv.begin(), vv.begin() + 3);
    if (vv[0] + vv[1] > vv[2]) {
      cout << "TRIANGLE";
      return 0;
    }
    else if (vv[0] + vv[1] == vv[2]) {
      f = true;
    }

  } while (next_permutation(all(v)));

  if (f) cout << "SEGMENT";
  else cout << "IMPOSSIBLE";

  return 0;
}