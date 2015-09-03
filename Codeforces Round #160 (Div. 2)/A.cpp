// http://codeforces.com/contest/262/problem/A

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
#define MAXNODES 1000

int count(int n){
	int r=0;
	while(n){
		int t = n%10;
		if(t == 4 || t==7) r++;
		n/=10;
	}
	return r;
}

int main(){
	int n,k,res=0,tmp;
	cin >> n >> k;
	while(n--){
		cin >> tmp;
		int r = count(tmp);
		if(r<=k) res++;
	}

	cout << res << endl;

	return 0;
}
