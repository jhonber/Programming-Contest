// http://codeforces.com/contest/106/problem/B

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


bool comp(pii a, pii b){
	return a.second > b.second;
}

int main(){
	int n;
	cin >> n;
	vector< vi > v;
	vi paila(n+2,1);

	FR(i,n){
		vi tmp(4);
		cin >> tmp[0] >> tmp[1] >> tmp[2] >> tmp[3];
		v.PB(tmp);
	}


	FR(i,n){
		FR(j,n){
			if(i==j) continue;
			if( v[i][0] < v[j][0] && v[i][1] < v[j][1] && v[i][2] < v[j][2]) paila[i] = 0;
		}
	}
	
	int mmin = INT_MAX;
	int ans = 0;
	FR(i,n){
//		cout << paila[i]<< " ";
		if(paila[i] && v[i][3]<mmin){
			mmin = v[i][3];
			ans = i;
		}
	}
	cout << ans+1 << endl;

	return 0;
}