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

typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef pair <int,int> pii;
#define MAXN 1000

int main(){
    int n,m;
		cin>>n>>m;
    
		vi boys(n,0), girls(m,0);
    set<pii> t;
		fr(i,0,n){
			fr(j,0,m){
				if(!boys[i] || !girls[j] ){
					t.insert(MK(i+1,j+1));
					boys[i]++; girls[j]++;
				}
			}
		}
	
		cout << t.size() << endl;
		set<pii> ::iterator it=t.begin();
   	for(;it!=t.end();++it){
			cout << it->first << " " << it->second << endl;
		}
    return 0; 
}
