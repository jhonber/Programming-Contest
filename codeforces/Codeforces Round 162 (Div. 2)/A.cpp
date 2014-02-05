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
	string line1, line2;
	int res=1, t=0;
	cin >> line1 >> line2;
	FR(i,line1.size()){
		fr(j,t,line2.size()){
			t++;
			if(line1[i] == line2[j]) { res++; break; }
		}
	}
	cout << res << endl;

	return 0;
}
