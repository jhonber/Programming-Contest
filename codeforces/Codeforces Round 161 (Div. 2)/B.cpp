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
#define PB push_back
#define D(x) cout<< #x " = "<<(x)<<endl
#define Dbg if(1)
#define MAXNODES 1000


int main(){
	int n, k, tmp,posx=0, posy=0;
	vector<int> v;
	cin >> n >> k;

	FR(i,n){
		cin >> tmp;
		v.PB(tmp);
	}
	if(k>n) cout << -1 << endl;
	else {
		sort(v.begin(),v.end());
		posx = v[n-k];
		cout << posx << " " << posy << endl;
	}
	return 0;
}




