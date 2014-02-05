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
#define MAXN 1000000000
typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef set<int> sti;

int pw(int a, int b){
	if(a==0) return 0;
	int ans = 1;
	while(b--) ans *= a;	
	return ans;
}

int brute(int a, int b, int n){
	int x = 0;
	if(a==0 && b==0) return 1;
	else if(a==0) return MAXN;
	else if(b==0) return 0;
	while( abs(a*pw(x,n)) < abs(b) ) x++;
	if(a*pw(x,n) == b) return x;
	else if (a*pw(-x,n) == b) return -x;
	return MAXN;
}

int main(){
	int a,b,n;
	cin >> a >> b >> n;
	int t = brute(a,b,n);
	if(t==MAXN) cout << "No solution" << endl;
	else cout << t << endl;
  return 0;
}