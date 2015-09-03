// http://codeforces.com/contest/230/problem/B

#include<bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

#define foreach(it, x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define all(x) x.begin(),x.end()
#define D(x) cout << #x " = " << (x) << endl;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

int dx[8] = {-1,-1,-1,0,1,1, 1, 0};
int dy[8] = {-1, 0, 1,1,1,0,-1,-1};

typedef long long   lli;
typedef vector<int> IV;

#define Sc(t,v) static_cast<t>(v)
#define cFor(t,v,c)  for(t::const_iterator v=c.begin(); \
v != c.end(); v++)

//Cuidado con estas macros, son la parte mas fundamental
//del algoritmo
#define ISCOMP(n)  (_c[(n)>>5]&(1<<((n)&31)))
#define SETCOMP(n) _c[(n)>>5]|=(1<<((n)&31))
namespace Num{
  const int MAX = 1000000;  // sqrt(10^12)
  const int LMT = 1000;   // sqrt(MAX)
  int _c[(MAX>>5)+1];
  IV primes;
  void primeSieve() {
    SETCOMP(0); SETCOMP(1);
    for (int i = 3; i <= LMT; i += 2)
      if (!ISCOMP(i))
        for (int j = i*i; j <= MAX; j+=i+i) SETCOMP(j);
    primes.push_back(2);
    for (int i=3; i <= MAX; i+=2)
	  if (!ISCOMP(i)) primes.push_back(i);
  }
}

using Num::primes;

int main(){__
  Num::primeSieve();
  int n;
  cin >> n;

  long long t;
  for(int i=0; i<n; ++i){
    cin >> t;
    long long s = sqrt(t);
    if( s*s == t  && binary_search(all(primes),s) )
      cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}