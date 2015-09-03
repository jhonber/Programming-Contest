// http://codeforces.com/contest/513/problem/B1

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
  int n,m;
  cin >> n >> m;


  vector<int> v(n),vv(n),vvv;
  for (int i = 1; i <= n; ++i) v[i - 1] = i;
  vv = v;

  long long paila = -INT_MAX;
  do {
    long long ans = 0;
    for (int i = 0 ; i < n; ++i) {
      long long sum = 0;
      for (int j = i; j < n; ++j) {
        int mmin = INT_MAX;
        int f = false;
        for (int k = i; k <= j; ++k) {
          mmin = min(mmin, v[k]);
          f = true;
        }
        if (f) sum += mmin;
      }
      ans += sum;
    }
    vvv.push_back(ans);
    if (paila < ans) paila = ans;
  } while (next_permutation(all(v)));

  int x = 0, cnt = 1;
  do {
    if (vvv[x] == paila) {
      if (cnt == m) {
        for (int i = 0; i < n; ++i) cout << " " << vv[i];
        break;
      }
      cnt ++;
    }
    x++ ;
  } while (next_permutation(all(vv)));

  return 0;
}