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
#define MAXNODES 1000

typedef long long int i6;
typedef vector<i6> vl;
typedef vector<int> vi;
typedef vector<int,int> vii;
typedef vector<vi> vvi;
typedef pair <int,int> pii;


int main(){
	int n;
	string s;
	getline(cin,s);
	
	n = atoi(s.c_str());
	
	FR(i,n){
		getline(cin,s);
		if(s.size()<5){
			cout << "OMG>.< I don't know!" << endl;
			continue;
		}
		string t = s.substr(0,5);
		string t2 = s.substr(s.size()-5,5);
//		D(t); D(t2);

		if(t2=="lala." && t!="miao.") cout << "Freda's" << endl;
		else if(t2!="lala." && t=="miao.") cout << "Rainbow's" << endl;
		else cout << "OMG>.< I don't know!" << endl;

	}
  return 0;
	
}



