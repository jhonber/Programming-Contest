// http://codeforces.com/contest/336/problem/A

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

int main(){
  int x,y;
  cin >> x >> y;

  int xx = abs(x) + abs(y);

  if( x < 0 && y > 0 )
    cout << -xx << " " << 0 << " " << 0 << " " << xx << endl;

  else if( x > 0 && y > 0 )
    cout << 0 << " " << xx << " " << xx << " " << 0 << endl;

  else if( x < 0 && y < 0 )
    cout << -xx << " " << 0 << " " << 0 << " " << -xx << endl;

  else
    cout << 0 << " " << -xx << " " << xx << " " << 0 << endl;

  return 0;
}