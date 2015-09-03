// http://codeforces.com/contest/60/problem/A

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
  vector<int> v(n,0);

  string a,b;
  int tmp;
  set<int> vv;
  set<int> vvv;

  int c1=0, c2=0;
  int paila = false;

  for(int i=0; i<m; ++i){
    cin >> a >> a >> b >> a >> tmp;
    tmp --;
    if(b=="left"){
      vv.insert(tmp);
      if(tmp-1 < 0)
        paila = true;
      for(int x=tmp-1; x>=0; --x)
        v[x]++;

      c1 ++;
    }
    else {
      vvv.insert(tmp);
      if(tmp+1>=n)
        paila = true;
      for(int x=tmp+1; x<n; ++x)
        v[x]++;

      c2 ++;
    }
  }

  foreach(i,vv){
    foreach(j,vvv){
      if(*i == *j || abs(*i-*j)==1) {
        cout << -1;
        return 0;
      }
    }
  }

  if(paila){
    cout << -1;
    return 0;
  }

  sort(all(v));

  int mmax = v[n-1];
  int ans = 0;

  for(int i=0; i<n; ++i)
    if(v[i] == mmax)
      ans ++;

  cout << ans;
  return 0;
}