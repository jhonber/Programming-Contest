// http://codeforces.com/contest/492/problem/A

#include<bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define foreach(it, x) for (__typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define all(x) x.begin(),x.end()
#define d(x) cout << #x " = " << (x) << endl;

template <class t> string tostr(const t &x)
{ stringstream s; s << x; return s.str(); }

template <class t> int toint(const t &x)
{ stringstream s; s << x; int r; s >> r; return r; }

int dx[8] = {-1,-1,-1,0,1,1, 1, 0};
int dy[8] = {-1, 0, 1,1,1,0,-1,-1};

int sum(int n) {
  return (n * (n + 1 ) ) / 2;
}


int main(){ __
  int n;
  cin >> n;

  int ans = 0;
  int i = 1;
  while (n > 0) {
    n -= sum(i);
    if (n >= 0) ans ++;
    i ++;
  }

  cout << ans;
  return 0;
}