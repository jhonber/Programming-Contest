// http://codeforces.com/contest/265/problem/B

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
#define PB push_back
#define Dbg if(1)
#define MAXNODES 1000

int main(){
	vector<int> v;
	int n,res=0,tmp;
	cin >> n;
	FR(i,n){
		cin >> tmp;
		v.PB(tmp);
	}

	if(n>1){
		FR(i,n-1){
			if(i==0) res += v[0];
			if(v[i]!=v[i+1]) res += abs(v[i]-v[i+1]);
		}

		res += n-1 + n;
		cout << res << endl;	
	}
	else cout << n+1 << endl;
	
	return 0;
}
