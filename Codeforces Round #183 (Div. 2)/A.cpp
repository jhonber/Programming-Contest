// http://codeforces.com/contest/304/problem/A

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

typedef long long int ll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector< pair<int,int> > vpi;
typedef vector<int,int> vii;
typedef vector<vi> vvi;
typedef pair <int,int> pii;

int gcd(int a, int b){
	if(a%b==0) return b;
	return gcd(b,a%b);
}

int main(){
  int n,ans=0;
  cin >> n;
	fr(i,1,n+1){
		fr(j,1,n+1){
			if(i*i+j*j > n) break;
			if( (i-j)%2==1 && i > j && gcd(i,j)==1) ans += n/(i*i+j*j);
		}
	}
	cout << ans << endl;
  return 0;
}