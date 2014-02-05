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
#define Dbg if(1)
#define PB push_back
#define MK make_pair
#define MAXNODES 1000

typedef long long int i6;
typedef vector<i6> vl;
typedef vector<int> vi;
typedef vector< pair<int,int> > vpi;
typedef vector<int,int> vii;
typedef vector<vi> vvi;
typedef pair <int,int> pii;

int main(){
  int n,m,t;
  cin >> n >> m;
  vpi q;
  int none=0, pone=0;

  FR(i,n){
    cin >> t;
    if(t>0) pone++;
    else none++;
  }
  
  int mmax = min(none,pone) * 2;
   
  FR(i,m){
    int l, r;
    cin >> l >> r;
    t = (r-l)+1;
    if(t%2!=0) cout << 0 << endl;
    else if(t <= mmax) cout << 1 << endl;
    else cout << 0 << endl;
  }
 
  return 0;
}



