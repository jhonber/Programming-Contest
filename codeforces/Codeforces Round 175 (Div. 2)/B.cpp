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


int main(){
  int n,s,t;
  cin >> n >> s >> t;
  s--; t--;

  if(s==t){
    cout << 0 << endl;
    return 0;
  }

  vi p;
  FR(i,n){
    int t;
    cin >> t;
    p.PB(t-1);
  }
  
  int act = s, ant;
  int res = 0;
  while(true){
    ant = act;
    act = p[act];
    res++;
    if(act == t){
      cout << res << endl;
      return 0;
    }
    if(act == ant || act==s){
      cout << -1 << endl;
      return 0;
    }
  }
  return 0;
}

