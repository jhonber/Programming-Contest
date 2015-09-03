// http://codeforces.com/contest/389/problem/A

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
  int n;
  cin >> n;

  int v[n];
  for(int i=0; i<n; ++i){
    cin >> v[i];
  }

  while(true){
    sort(v,v+n);
    int ff = false;

    for(int i=n-1; i>=0 ; --i){
      int f = false;
      for(int j=i-1; j>=0; --j){
        if(v[i] > v[j]){
          v[i] = v[i] - v[j];
          f = true;
          break;
        }
      }
      if(f) break;
      else ff = true;
    }
    if(ff) break;
  }

  int ans = 0;
  for(int i=0; i<n; ++i)
    ans += v[i];

  cout << ans;
  return 0;
}