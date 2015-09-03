// http://codeforces.com/contest/436/problem/B

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


int n,m,k;
bool check(int i, int j){
  if ( i>=1 && i<=n && j>=1 && j<=m )
    return true;
  return false;
}

int main(){__
  cin >> n >> m >> k;

  vector<int> ans(2222,0);

  for (int i=1; i<=n; ++i){
    for (int j=1; j<=m; ++j){
      char t;
      cin >> t;
      if (t != '.'){
        if ( t=='U' && i%2 != 0 )
          ans[j] ++;

        if ( t=='R' && check(i-(i-1),j+(i-1)) )
          ans[j+(i-1)] ++;

        if ( t=='L' && check(i-(i-1),j-(i-1)) )
          ans[j-(i-1)] ++;
      }
    }
  }

  for (int i=1; i<=m; ++i)
    cout << ans[i] << " ";

  return 0;
}
