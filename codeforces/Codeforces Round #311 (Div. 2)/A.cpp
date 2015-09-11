// http://codeforces.com/contest/557/problem/A

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

  int summ = 0;
  vector<int> v(6);
  vector<int> ans;

  for (int i = 0; i < 6; ++i) {
    cin >> v[i];
    if (i % 2 == 0) {
      summ += v[i];
      ans.push_back(v[i]);
    }
  }

  n -= summ;
  for (int i = 0, j = 1; i < 3; ++i, j += 2) {
    int rest = v[j] - ans[i];
    if (n > 0) {
      int t = min(rest, n);
      ans[i] += t;
      n -= t;
    }
  }

  cout << ans[0] << " " << ans[1] << " " << ans[2];
  return 0;
}