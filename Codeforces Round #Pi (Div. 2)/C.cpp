// http://codeforces.com/contest/567/problem/C

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
  int n, k;
  cin >> n >> k;

  vector<long long> v(n);
  map<long long, long long> left;
  map<long long, long long> right;

  for (int i = 0; i < n; ++i) {
    cin >> v[i];
    right[v[i]] ++;
  }

  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    right[v[i]] --;
    if ( v[i] % k == 0 ) {
      long long a = v[i] / k;
      long long b = v[i] * k;
      ans += left[a] * right[b];
    }

    left[v[i]] ++;
  }

  cout << ans;
  return 0;
}