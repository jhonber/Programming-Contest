// http://codeforces.com/contest/569/problem/C

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

const int mx = 1e7 + 10;

typedef long long   lli;
typedef vector<int> IV;

bool primes[mx];

#define Sc(t,v) static_cast<t>(v)
#define cFor(t,v,c)  for(t::const_iterator v=c.begin(); \
v != c.end(); v++)

//Cuidado con estas macros, son la parte mas fundamental
//del algoritmo
#define ISCOMP(n)  (_c[(n)>>5]&(1<<((n)&31)))
#define SETCOMP(n) _c[(n)>>5]|=(1<<((n)&31))
namespace Num{
  const int MAX = 1e7 + 10;  // sqrt(10^12)
  const int LMT = 3164;   // sqrt(MAX)
  int _c[(MAX>>5)+1];
  void primeSieve() {
    SETCOMP(0); SETCOMP(1);
    for (int i = 3; i <= LMT; i += 2)
      if (!ISCOMP(i))
        for (int j = i*i; j <= MAX; j+=i+i) SETCOMP(j);
    primes[2] = true;
    for (int i=3; i <= MAX; i+=2)
	  if (!ISCOMP(i)) primes[i] = true;
  }
}

bool is_pal(int p){
    int pp = p;
    int r = 0;
    while (pp) {
        r = r * 10 + pp % 10;
        pp /= 10;
    }
    return p == r;
}
int main() {
  int p, q;
  cin >> p >> q;

  Num::primeSieve();

  int n1 = 0, n2 = 0, ans = 0;
  for (int i = 1; i <= mx; ++i) {
    if (primes[i]) n1 ++;
    if (is_pal(i)) n2 ++;
    if ((long long)n1 * q <= (long long)n2 * p) ans = i;
  }

  cout << ans;
  return 0;
}