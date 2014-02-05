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
	string line;
	vs all;
	int may = 0;
	int cuadrar = 0;
	while(getline(cin,line)){
		all.PB(line);
		if(line.size() > may) may = line.size();
	}

	FR(i,may+2) cout << "*";
	cout << endl;

	FR(i,all.size()){
		cout <<"*";
		int s = all[i].size();
		int mid = may - s;
		if(mid==0) cout << all[i];
		else if(mid%2==0){
			FR(x,mid/2) cout << " ";
			cout << all[i];
			FR(x,mid/2) cout << " ";
		}
		else {
			if(cuadrar%2 == 0){
				FR(x,mid/2) cout << " ";
				cout << all[i];
				FR(x,(mid/2)+1) cout << " ";
			}
			else {
				FR(x,(mid/2)+1) cout << " ";
				cout << all[i];
				FR(x,mid/2) cout << " ";
			}
			cuadrar++;
		}
		cout <<"*" <<endl;
	}

	FR(i,may+2) cout << "*";
	cout << endl;
	return 0;
}