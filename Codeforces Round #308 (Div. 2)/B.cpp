// http://codeforces.com/contest/552/problem/B

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
  long long n;
  cin >> n;

  if (n < 10) {
    cout << n;
    return 0;
  }

  long long ans = 0;
  long long p = 10;
  long long ant = 1;
  int cnt = 1;
  while (true) {
    if (p - 1 <= n) {
      ans += cnt * (p - ant);
      cnt ++;
      ant = p;
      p *= 10;
    } else break;
  }

  if (p > n) {
    if (ant - 1 <= n) n -= ant - 1;
  }
  else n -= p;
  cout << ans + (cnt * n);
  return 0;
}