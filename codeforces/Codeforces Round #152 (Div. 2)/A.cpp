// http://codeforces.com/contest/248/problem/A

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

const int INF = 10e8;

int main(){__
  int n;
  cin >> n;

  int left = 0;
  int right = 0;

  for(int i=0; i<n; ++i){
    int a,b;
    cin >> a >> b;
    left += a;
    right += b;
  }

  cout << min( left,n-left ) + min(right,n-right);
  return 0;
}