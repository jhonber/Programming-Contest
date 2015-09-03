// http://codeforces.com/contest/276/problem/D

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
  unsigned long long l,r;
  cin >> l >> r;

  int ind = 0;
  for (int i = 63; i >= 0; --i) if ((1LL << i) & (l ^ r) ) {
    i += 1;
    cout << (1LL << i) - 1;
    return 0;
  }

  cout << 0;
  return 0;
}