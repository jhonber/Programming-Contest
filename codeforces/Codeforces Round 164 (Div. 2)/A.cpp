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

const double pi=acos(-1);

int main(){
  int n,res=0,tmp1,tmp2;
	vi v1,v2;
	cin >> n;
	FR(i,n){
		cin >> tmp1;
		cin >> tmp2;
		v1.PB(tmp1);
		v2.PB(tmp2);
	}

	FR(i,n)
		FR(j,n)
			if(v1[i]==v2[j]) res++;

	cout << res << endl;

  return 0;
}



