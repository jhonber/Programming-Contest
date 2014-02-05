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
#ifdef NO
#ifdef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif
#endif

typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef map<string,int> msi;
typedef vector< pair<string,int> > vpsi;

int main(){
  int n;
  cin >> n;
  msi mapa,mapa2;
  vpsi v;
  int  max = -INT_MAX;
  string res;
  
  FR(i,n){
    string name;
    int s;
    cin >> name >> s;
    mapa[name] += s;
    v.PB(MK(name,s));
  }

  FR(i,v.size()) if( mapa[v[i].first] > max ) max = mapa[v[i].first];

  msi win;
  msi::iterator it = mapa.begin();
  for(;it!=mapa.end();++it)
    if(it->second==max)
      win[it->first]++;


  FR(i,v.size()){
    mapa2[v[i].first] += v[i].second;
    if(mapa2[v[i].first] >= max && win[v[i].first]) {
      cout << v[i].first << endl;
      return 0;
    }
  }
 
  return 0;
}







