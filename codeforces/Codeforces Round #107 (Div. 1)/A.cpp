// http://codeforces.com/contest/150/problem/A

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

bool isPrime(long long n) {
  long long i = 2;
  while ( i * i <= n) {
    if (n % i == 0) return false;
    i++;
  }
  return true;
}

int main() {
  long long q;
  cin >> q;
  if (q == 1 || isPrime(q)) {
    cout << 1 << endl << 0;
    return 0;
  }

  long long i = 2;
  long long ans = LLONG_MAX;

  while ( i * i <= q ) {
    if (q % i == 0) {
      long long div = q / i;
      if (!isPrime(div) and div < ans) ans = div;
      if (!isPrime(i) and i < ans) {
        ans = i;
        break;
      }
    }
    i ++;
  }

  if (ans == LLONG_MAX) cout << 2;
  else cout << 1 << endl << ans;

  return 0;
}