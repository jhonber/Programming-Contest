// http://codeforces.com/contest/415/problem/A

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
  int n,m;
  cin >> n >> m;

  vector<int> v(n+1,0);

  for(int i=0; i<m; ++i){
    int t;
    cin >> t;

    for(int j=t ;j<=n;++j){
      if(!v[j])
        v[j] = t;
    }
  }


  for(int i=1; i<=n; ++i){
    cout << " " << v[i];
  }

  return 0;
}