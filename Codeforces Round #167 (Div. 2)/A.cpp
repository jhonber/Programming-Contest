// http://codeforces.com/contest/272/problem/A

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
#define MAXNODES 1000

typedef long long int i6;
typedef vector<int> vi;
typedef vector<int,int> vii;
typedef vector<vi> vvi;
typedef pair <int,int> pii;

const double pi=acos(-1);

int main(){
  int n,t,sum=0;
	cin >> n;
	FR(i,n){
		cin >> t;
		sum += t;
	}
	
	int t2 = sum-1%(n+1);
	int res=0;
	fr(i,1,6)
		if((i+t2)%(n+1) != 0) res++;
	
	cout << res << endl;

  return 0;
}



