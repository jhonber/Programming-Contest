// http://codeforces.com/contest/218/problem/B

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

  vector<int> v(m);
  for(int i=0; i<m; ++i){
    cin >> v[i];
  }

  sort(all(v));

  int mmin = 0;
  int n2 = n;
  vector<int> vv = v;

  int i = 0;
  while(n2 && i<m){
    if(vv[i]>0){
      mmin += vv[i];
      vv[i] --;
      n2 --;
    }
    else i++;
  }

  int mmax = 0;
  n2 = n;
  vv = v;
  i = m-1;

  while(n2>0){
    if(vv[i]>0){
      mmax += vv[i];
      n2 -= 1;
      vv[i] -= 1;
    }
    sort(all(vv));
  }

  cout << mmax << " " << mmin;
  return 0;
}