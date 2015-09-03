// http://codeforces.com/contest/483/problem/A

#include<bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define foreach(it, x) for(__typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define all(x) x.begin(),x.end()
#define D(x) cout << #x " = " << (x) << endl;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

int dx[8] = {-1,-1,-1,0,1,1, 1, 0};
int dy[8] = {-1, 0, 1,1,1,0,-1,-1};

int main(){ __
  long long l,r;
  cin >> l >> r;

  long long i,j;
  for (;l <= r; ++ l) {
    for ( i = l + 1; i <= r; ++ i) {
      for ( j = i + 1; j <= r; ++ j) {
        if ( __gcd(l,i) == 1 && __gcd(i,j) == 1 && __gcd(l,j) != 1 ) {
          cout << l << " " << i << " " << j;
          return 0;
        }
      }
    }
  }

  cout << -1;
  return 0;
}