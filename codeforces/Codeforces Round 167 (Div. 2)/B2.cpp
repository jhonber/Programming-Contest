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

#define fr(i,j,n) for(int i=j;i<n;++i)
#define FR(i,n) fr(i,0,n)
#define foreach(x,v) for(typeof (v).begin() x = (v).begin(); x!= (v).end(); x++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define D(x) cout<< #x " = "<<(x)<<endl
#define Dbg if(1)
#define PB push_back
#define MAX 100010

typedef long long int i6;
typedef vector<int> vi;
typedef vector<int,int> vii;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef map<int,i6> mii6;

const double pi=acos(-1);

i6 countbits(i6 n){
	i6 c=0;
	while(n){
		if( n & 1 ) c++;
		n >>= 1;
	}
	return c;
}

i6 sum(i6 n){ return (n*(n+1))/2; }

int main(){
	int n,t;
	i6 res=0;
	cin >> n;
	mii6 mapa;

	while(n--){
		cin >> t;
		mapa[countbits(t)] ++;
	}
	
	mii6::iterator it = mapa.begin();
	for(it; it!=mapa.end(); ++it) res += sum(it->second-1);

	cout << res << endl;
	
  return 0;
}