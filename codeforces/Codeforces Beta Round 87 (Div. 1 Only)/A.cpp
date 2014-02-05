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
#define D(x) cout<< #x " = "<<(x)<<endl
#define PB push_back
#define MK make_pair
#define N 2000

typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair <int,int> pii;
typedef pair <double,double> pdd;

vi visited(N+50);
vi cost(N+50);
vvi G(N+50);

int dfs(int i){
	stack<int> Q;
	Q.push(i);
	visited[i]=true;
	int mmax = 0;

	while(!Q.empty()){
		int v = Q.top(); Q.pop();

		FR(w,G[v].size()){
			if( !visited[G[v][w]] ){
				visited[G[v][w]] = true;
				cost[G[v][w]] = cost[v]+1;
				mmax = cost[v]+1 > mmax ? cost[v]+1 : mmax;
				Q.push(G[v][w]);
			}
		}
	}
	return mmax+1;
}

int main(){
	int n,a;
	cin >> n;
	FR(i,n){
		cin >> a;
		if(a!=-1) G[a-1].PB(i);
	}

	int ans = 1;
	FR(i,n){
		FR(j,n) visited[j] = cost[j] = 0;
		int t = dfs(i);
		ans = t > ans ? t : ans;
	}

	cout << ans << endl;

  return 0;
}