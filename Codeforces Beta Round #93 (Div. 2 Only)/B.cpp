// http://codeforces.com/contest/127/problem/B

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
	int n;
	cin >> n;
	vi v;
	FR(i,n){
		int t;
		cin >> t;
		v.PB(t);
	}
	sort(all(v));

	int ans = 0;
	FR(i,n-1){
		if(v[i]==v[i+1]) {
			ans++;
			i++;
		}
	}
	cout << ans/2 << endl;
	return 0;
}