// http://codeforces.com/contest/11/problem/A

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
#define Dd(x) printf("#x = %lf\n", x)
#define Dbg if(1)
#define PB push_back
#define MAXN 1000

typedef long long int ll;
typedef vector<ll> vl;
typedef vector< string > vs;
typedef vector<int> vi;
typedef vector<int,int> vii;
typedef vector<vi> vvi;
typedef pair <int,int> pii;
typedef pair <string,string> pss;
typedef vector<pss> vpss;
typedef pair <double,double> pdd;


int main(){
	int n,d,a,b;
	cin >> n >> d;
	cin >> a;

	int ans = 0;
	FR(i,n-1){
		cin >> b;
		if(a>b){
			double x = ceil(((double)a - (double)b) / (double)d);
			b += d*x;
			ans += x;
		}
		if(a==b) {
			b += d;
			ans++;
		}
		a = b;
	}

	cout << ans << endl;
	return 0;
}