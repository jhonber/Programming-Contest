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
	if(n==1){
		int t;
		cin >> t;
		cout << "NO" << endl;
		return 0;
	}
	set<int> st;
	FR(i,n){
		int t;
		cin >> t;
		st.insert(t);
	}
	if(st.size()==1){
		cout << "NO" << endl;
		return 0;
	}
	set<int> ::iterator it=st.begin();
	it++;
	cout << *it << endl;
}