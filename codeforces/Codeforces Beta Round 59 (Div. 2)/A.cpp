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
	vpss v;
	FR(i,n){
		pss t;
		cin >> t.first >> t.second;
		v.PB(t);
	}

	while(v.size()>1){
		FR(i,v.size()){
			if(v[i].second=="rat"){
				cout << v[i].first << endl;
				v.erase(v.begin()+i);
				i--;
			}
		}
		FR(i,v.size()){
			if(v[i].second=="child" || v[i].second=="woman"){
				cout << v[i].first << endl;
				v.erase(v.begin()+i);
				i--;
			}
		}
		FR(i,v.size()){
			if(v[i].second=="man"){
				cout << v[i].first << endl;
				v.erase(v.begin()+i);
				i--;
			}
		}
	}
	cout << v[0].first << endl;
	return 0;
}