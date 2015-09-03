// http://codeforces.com/contest/149/problem/A

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

int main(){__
  int k;
  cin >> k;

  int v[12];
  for(int i=0; i<12; ++i)
    cin >> v[i];

  sort(v,v+12);

  int c = 0, ans=0;
  for(int i=11; i>=0 && c<k; --i,ans++)
    c += v[i];

  if(c<k)
    cout << -1;
  else
    cout << ans;

  return 0;
}