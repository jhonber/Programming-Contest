// http://codeforces.com/contest/478/problem/B

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

long long sum (long long n) {
  return (n * (n - 1)) / 2;
}

int main() {
  int n,m;
  cin >> n >> m;

  int a = n / m;
  int res = n - (a * m);

  long long mmin = (sum(a) * (m - res)) + ( sum(a + 1) * res);
  long long mmax = sum(n - (m - 1));

  cout << mmin << " " << mmax << endl;
  return 0;
}