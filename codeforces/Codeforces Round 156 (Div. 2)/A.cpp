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

typedef long long int ll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef pair <int,int> pii;


int main(){
	int n;
	cin >> n;
	int a=0, b=0, c=0;
	int cont = 1;
	FR(i,n){
		if(cont==4) cont=1;
		int t;
		cin >> t;
		if(cont==1) a+=t;
		else if(cont==2) b+=t;
		else c+=t;
		cont ++;
	}
	
	if(a>b && a>c) cout << "chest";
	else if(b>a && b>c ) cout << "biceps";
	else cout << "back";
}