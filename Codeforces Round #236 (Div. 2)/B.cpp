// http://codeforces.com/contest/402/problem/B

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
  int n,k;
  cin >> n >> k;

  if(n==1){
    cout << 0;
    return 0;
  }

  int v[n];
  for(int i=0; i<n; ++i)
    cin >> v[i];


  int best = 0;
  int mmax = -1;

  for(int i=0; i<n; ++i){
    int tmp = 0;
    int f = true;
    for(int j=i+1, kk = v[j-1]+k; j<n; ++j, kk += k){
      if( kk == v[j] )
        tmp ++;
    }

    for(int j=i-1, kk = v[j+1]-k; j>=0; --j, kk -= k){
      if( kk == v[j] )
        tmp ++;
      if(kk<=0)
        f = false;
    }

    if(tmp > mmax && f){
      best = i;
      mmax = tmp;
    }
  }

  vector<string> ans;
  for(int j=best+1, kk = v[j-1]+k; j<n; ++j, kk += k){
    if( kk != v[j] ){
      if(kk>v[j]){
        ans.push_back( "+ " + toStr(j+1) + " " + toStr(kk-v[j]) );
      }
      else {
        ans.push_back( "- " + toStr(j+1) + " " + toStr(v[j]-kk) );
      }
    }
  }

  for(int j=best-1, kk = v[j+1]-k; j>=0; --j, kk -= k){
    if( kk != v[j] ){
      if(kk>v[j]){
        ans.push_back( "+ " + toStr(j+1) + " " + toStr(kk-v[j]) );
      }
      else {
        ans.push_back( "- " + toStr(j+1) + " " + toStr(v[j]-kk) );
      }
    }
  }

  cout << ans.size() << endl;
  for(int i=0; i<ans.size(); ++i){
    cout << ans[i] << endl;
  }

  return 0;
}