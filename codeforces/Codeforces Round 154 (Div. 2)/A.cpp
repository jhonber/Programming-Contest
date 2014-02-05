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
  int n,m;
  freopen("input.txt","r",stdin);
  cin >> n >> m;

  int n2 = n, m2 = m;
  int t = n*m;
  int t2 = max(n,m);
  int t3 = min(n,m);
  int r = t2 - (t2 - t3);

  string res = "";

  int t4 = n > m ? 0 : 1;
  FR(i,2*r){
    if(n>0 && i%2==t4){
      res += "B";
      n--;
    }
    else if(m>0) {
      res += "G";
      m--;
    }
  }
  FR(i,t2-r){
    if(n2>m2) res += "B";
    else res += "G";
  }
  
  freopen("output.txt","w",stdout);
  cout << res << endl;
  

  return 0;
}

