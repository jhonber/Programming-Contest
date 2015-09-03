// http://codeforces.com/contest/219/problem/A

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

  string s;
  cin >> s;

  vector<char> v(s.size());
  for (int i = 0; i < s.size(); ++i) v[i] = s[i];

  vector<string> ans(n);
  sort(all(v));

  int j = 0;
  for (int i = 0; i < s.size(); ++i, ++j) ans[j % n] += toStr(v[i]);

  for (int i = 1; i < n; ++i) if (ans[i] != ans[i - 1]) {
    cout << -1;
    return 0;
  }

  for (int i = 0; i < n; ++i) cout << ans[i];
  return 0;
}