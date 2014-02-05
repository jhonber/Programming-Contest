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

#define MPI acos(-1)
#define fr(i,j,n) for(int i=j;i<n;++i)
#define FR(i,n) fr(i,0,n)
#define foreach(x,v) for(typeof (v).begin() x = (v).begin(); x!= (v).end(); x++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define RI(x) scanf("%d",&x)
#define DRI(x) int x;RI(x)
#define RII(x,y) scanf("%d%d",&x,&y)
#define DRII(x,y) int x,y;RII(x,y)
#define PI(x) printf("%d ",x)
#define PIS(x) printf("%d\n",x)
#define D(x) cout<< #x " = "<<(x)<<endl
#define Dd(x) printf("#x = %lf\n", x)
#define Dbg if(1)
#define PB push_back
#define MK make_pair
#define F first
#define S second

typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<int,int> vii;
typedef vector<vi> vvi;
typedef pair <int,int> pii;
typedef pair <double,double> pdd;

const double EPS = 1e-3;

int gcd(int a, int b){
  if(b==0) return a;
  else return gcd(b,a%b);
}

int main(){
	int n;
	cin >> n;
	vi v;
	FR(i,n){
		int t;
		cin >> t;
		v.PB(t);
	}

	int mmin = INT_MAX;
	int x,y;
	FR(i,n-1){
		int t = abs(v[i]-v[i+1]);
		if(t<mmin) {
			mmin = t;
			x = i; y = i+1;
		}
	}
	int t = abs(v[n-1]-v[0]);
	if(t<mmin){
		mmin = t;
		x = n-1; y = 0;
	}
	cout << x+1 << " " << y+1 << endl;

  return 0;
}