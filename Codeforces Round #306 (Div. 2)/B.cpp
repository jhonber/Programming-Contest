// http://codeforces.com/contest/550/problem/B

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

int n, l, r, x;
vector<int> v;
long long ans = 0;

void f (int i, long long tot, int mmin, int mmax) {
  if (tot <= r && tot >= l && (mmax - mmin) >= x && mmin != INT_MAX && mmax != -INT_MAX ) ans ++;
  if (tot > r) return;
  for (int j = i; j < n; ++j) {
    f (j + 1, tot + v[j], min(mmin, v[j]), max(mmax, v[j]));
  }
  return;
}

int main() {
  cin >> n >> l >> r >> x;
  int t;
  for (int i = 0; i < n; ++i) {
    cin >> t;
    v.push_back(t);
  }


  long long output = 0;
  for (int i = 0; i < n; ++i) {
    ans = 0;
    f(i,0,INT_MAX,-INT_MAX);
    output = max(output, ans);
  }

  cout << output;
  return 0;
}