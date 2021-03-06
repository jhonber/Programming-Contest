// http://codeforces.com/contest/485/problem/C

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

int bits(long long x) {
  int b = 0;
  while (x) {
    x /= 2;
    b++;
  }
  return b;
}

long long mpow(long long a, long long b) {
  long long p = 1;
  while ( b --> 0 )
    p *= a;
  return p;
}

long long toLL(bitset<64> s){
  long long n = 0;
  for (int i = 0; i < 64; ++i) 
    if(s[i]) n += mpow(2,i);
 
  return n;
}

long long f (long long l, long long r) {
  int b = bits(r);
  const int size = 64;
  bitset<size> ans = r;
  bitset<size> tmp;

  if (ans.count() == b) return r;
  for (int i = b - 1; i >= 0; --i) {

    tmp = ans;
    tmp[i] = 0;

    for (int j = i - 1; j >= 0; --j)
      tmp[j] = 1;

    long long tt = toLL(tmp);
    if (tt >= l && tt <= r)
      return tt;

    if (tt < l)
      ans[i] = 1;
  }
  return toLL(ans);
}

int main(){ __
  int n;
  long long l,r;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> l >> r;
    cout << f(l,r) << endl;
  }

  return 0;
}