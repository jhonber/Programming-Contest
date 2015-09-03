// http://codeforces.com/contest/525/problem/C

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

  vector<long long> v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];

  sort(all(v));

  long long ans = 0;
  int i = n - 1;
  while (i >= 3) {
    int ant = 0;
    if (v[i] - v[i - 1] <= 1) {
      ant = v[i - 1];
      i -= 2;
      while (i > 0) {
        if (v[i] - v[i - 1] <= 1) {
          ans += ant * v[i - 1];
          i --;
          break;
        }
        i --;
      }
    }
    i --;
  }

  cout << ans;

  return 0;
}