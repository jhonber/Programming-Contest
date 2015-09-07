// http://codeforces.com/contest/171/problem/A

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
  int a, b;
  cin >> a >> b;

  if (!a and !b) {
    cout << 0;
    return 0;
  }

  vector<int> aa;
  vector<int> bb;

  int t1 = 0, t2 = 0;
  if (!a) {
    aa.push_back(0);
    t1 = 1;
  }
  if (!b) {
    bb.push_back(0);
    t2 = 1;
  }

  while (a) {
    aa.push_back(a % 10);
    a /= 10;
    t1 ++;
  }

  while (b) {
    bb.push_back(b % 10);
    b /= 10;
    t2 ++;
  }

  int t = max (t1, t2);
  while (aa.size() < t) aa.push_back(0);
  while (bb.size() < t) bb.insert(bb.begin(), 0);

  int c = 0;
  vector<int> ans;
  for (int i = 0, j = t - 1; i < t; ++i, --j) {
    ans.push_back((aa[i] + bb[j] + c) % 10);
    c = (aa[i] + bb[j] + c) / 10;
  }
  if (c) ans.push_back(c);

  reverse(all(ans));

  int f = false;
  for (int i = 0; i < ans.size(); ++i) {
    if (ans[i]) f = true;
    if (!f) continue;
    cout << ans[i];
  }

  return 0;
}