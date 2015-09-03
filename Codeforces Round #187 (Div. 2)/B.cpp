// http://codeforces.com/contest/315/problem/B

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
#define Dbg if(1)
#define PB push_back
#define MK make_pair
#define MAXNODES 1000

typedef long long int ll;
typedef vector<ll> vl;
typedef vector<char> vc;
typedef vector<int> vi;
typedef vector<int,int> vii;
typedef vector<vi> vvi;
typedef pair <int,int> pii;
typedef pair <ll,ll> pll;
#define MAXN 100000

ll v[MAXN];
ll inc=0;

int main(){
	int n,q;
	cin >> n >> q;

//	memset(inc,0,sizeof(inc));

	FR(i,n){
		int t;
		cin >> t;
		v[i] = t;
	}

	FR(i,q){
		int t;
		cin >> t;
		if(t==1){
			int a, b;
			cin >> a >> b; a--;
			v[a] = b - inc;
		}
		else if(t==2){
			int a;
			cin >> a;
			inc += a;
		}
		else {
			int a;
			cin >> a; a--;
			cout << v[a] + inc << endl;
		}
	}
	
    return 0;
}

