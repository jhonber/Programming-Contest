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
typedef set<char> stc;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef vector<vi> vvi;
typedef pair <int,int> pii;
typedef pair <string,string> pss;
typedef vector < pss > vpss;
typedef pair <double,double> pdd;
typedef map<string,int> msi;

int main(){
	double h,m,a;
	scanf("%lf:%lf", &h,&m);
	h = h >= 12? h-12 : h;
	if(m==0){
		a = 1;
	}
	else {
		a = (60.0/m);
	}
	double x = m==0? 0 : 60.0/m;
	double tt;
	tt = (30/a);
	tt = tt == 30 ? 0 : tt;
	h = h==12 ? 0 : h;
	double t = h*30.0 + tt;
	double hora = t==360? 0 : t;
//	cout << (int)(t==360? 0 : t) << " " << m*6.0)<< endl;
	printf("%.1lf %.1lf",hora,m*6.0);
	
  return 0;
}