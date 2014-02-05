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
#define F first
#define S second

typedef long long int ll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef pair <int,int> pii;
typedef vector<pii> vpii;

#define MAXN 100

vvi G(MAXN+10);
vi visited(MAXN+10);

void dfs(int i){
	if(!visited[i]){
		visited[i] = true;
		for_each(all(G[i]), dfs);
	}
}

int main(){
	int n;
	cin >> n;

	vpii v;
	FR(i,n){
		int t,c,d;
		cin >> t >> c >> d;
		
		if(t==1){
			v.PB(MK(c,d));
			int x = v.size()-1;
			if(x > 0){
				FR(j,x){
					if( (c < v[j].F && v[j].F < d) || (c < v[j].S && v[j].S < d) ) G[j].PB(x);
					if( (v[j].F < c && c < v[j].S) || (v[j].F < d && d < v[j].S) ) G[x].PB(j);
				}
			}
		}
		else {
			c--; d--;
			FR(xx,visited.size()) visited[xx] = 0;
			dfs(c);
			cout << (visited[d] ? "YES" : "NO") << endl;
		}
	}

	return 0;
}

