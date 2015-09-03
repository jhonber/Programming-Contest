// http://codeforces.com/contest/460/problem/B

#include<bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define foreach(it, x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define all(x) x.begin(),x.end()
#define D(x) cout << #x " = " << (x) << endl;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

int dx[8] = {-1,-1,-1,0,1,1, 1, 0};
int dy[8] = {-1, 0, 1,1,1,0,-1,-1};

long long f(long long a, long long b, long long c, long long sx) {
  long long p = 1;
  while (a --> 0)
    p *= sx;

  return (b*p) + c;
}

long long f2(long long a, long long b, long long c, long long x) {
  long long sx = 0;
  while (x) {
    sx += x%10;
    x /= 10;
  }

  long long p = 1;
  while (a --> 0)
    p *= sx;
  return (b*p) + c;
}

int main(){ __
  long long a,b,c;
  cin >> a >> b >> c;

  vector<long long> ans;
  for (long long i=1; i <= 81; ++i) {
    long long x = f(a,b,c,i);
    if (f2(a,b,c,x) == x && x < 1e9 && x > 0)
      ans.push_back(x);
  }

  sort(all(ans));
  cout << ans.size() << endl;
  for (int i=0; i<ans.size(); ++i)
    cout << ans[i] << " ";

  return 0;
}