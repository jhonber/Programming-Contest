// http://codeforces.com/contest/496/problem/B

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

int main() { __
  int n;
  cin >> n;

  string num;
  cin >> num;

  vector<int> v(n),vv(n);
  for (int i = 0; i < n; ++i)
    v[i] = toInt(num[i]);

  vector<int> ans = v;
  for (int i = 0; i < n; ++i) {
    int first = v[0];
    for (int j = 0; j < n; ++j) {
      vv[j] = v[j] - first;
      if (vv[j] < 0) vv[j] += 10;
    }

    ans = min(ans, vv);
    int last = v[v.size() - 1]; v.pop_back();
    v.insert(v.begin(),last);
  }

  for (int i = 0; i < n; ++i) cout << ans[i];

  return 0;
}