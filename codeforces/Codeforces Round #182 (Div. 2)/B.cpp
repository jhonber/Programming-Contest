// http://codeforces.com/contest/302/problem/B

using namespace std;
#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<bitset>

#include<climits>
#include<cstring>
#include<cstdio>
#include<cmath>

#define PI acos(-1)
#define fr(i,j,n) for(int i=j;i<n;++i)
#define FR(i,n) fr(i,0,n)
#define foreach(x,v) for(typeof (v).begin() x = (v).begin(); x!= (v).end(); x++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define D(x) cout<< #x " = "<<(x)<<endl
#define Dbg if(1)
#define PB push_back
#define MK make_pair
#define MAXNODES 1000

typedef long long int ll;
typedef vector<ll> vl;
typedef pair <ll,ll> pll;
typedef vector<pll> vpl;

int main(){
  int n,m;
  cin >> n >> m;
  
  vpl songs;
  ll ci,ti;
  cin >> ci >> ti;
  songs.PB(MK(1,(ci*ti)));
  
  FR(i,n-1){
    cin >> ci >> ti;
    songs.PB(MK(songs[i].second+1, songs[i].second + (ci*ti)));
  }

  int j=0;
  FR(i,m){
    ll x;
    cin >> x;
    for(;j<n;j++) if(x >= songs[j].first && x<=songs[j].second) {cout << j+1 << endl; break;}
  }
  
  return 0;
}



