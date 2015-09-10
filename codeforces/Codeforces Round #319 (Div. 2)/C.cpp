// http://codeforces.com/contest/577/problem/C

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

int n;
set<int> ans;
void print(vector<int> v) {
  for (int i = 0; i < v.size(); ++i) cout << v[i] << " "; cout << endl;
}

void solve (int i, vector<int> v) {
  if (i > n or v.size() == 1) return;

  vector<int> a, b;
  for (int j = 0; j < v.size(); ++j) {
    if (v[j] % i == 0) a.push_back(v[j]);
    else b.push_back(v[j]);
  }

  if (a.size() > 0 and b.size() > 0) {
    ans.insert(i);
    solve (i + 1, a);
    solve (i + 1, b);
  }
  else solve(i + 1, v);

  return;
}

int main() {
  cin >> n;

  vector<int> v(n);
  for (int i = 1; i <= n; ++i) v[i - 1] = i;
  solve(2, v);

  cout << ans.size() << endl;
  foreach(x, ans) cout << *x << " ";
  return 0;
}