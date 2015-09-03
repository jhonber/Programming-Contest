// http://codeforces.com/contest/254/problem/A

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

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

#define PI acos(-1)
#define fr(i,j,n) for(int i=j;i<n;++i)
#define FR(i,n) fr(i,0,n)
#define foreach(x,v) for(typeof (v).begin() x = (v).begin(); x!= (v).end(); x++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define D(x) cout<< #x " = "<<(x)<<endl
#define Dd(x) printf("#x = %lf\n", x)
#define Dbg if(1)
#define PB push_back
#define MK make_pair
#define MAXNODES 1000

typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<int,int> vii;
typedef vector<vi> vvi;
typedef pair <int,int> pii;
typedef pair <double,double> pdd;
typedef vector<pii> vpii;
typedef map<int,int> mii;


int main(){
  int n;
  freopen("input.txt","r",stdin);
  cin >> n;

  vpii ans;
  mii mapa;
  FR(i,2*n){
    int t;
    cin >> t;
    ans.PB(MK(t,i+1));
    mapa[t] ++;
  }

  freopen("output.txt","w",stdout);

  mii::iterator it = mapa.begin();
  for(it; it!=mapa.end(); ++it){
    if(it->second % 2 == 1){
      cout << -1 << endl;
      return 0;
    }
  }

  sort(all(ans));
  for(int i=0; i<2*n; i+=2) cout << ans[i].second << " " << ans[i+1].second << endl;

  return 0;
}

