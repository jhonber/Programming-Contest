// http://codeforces.com/contest/266/problem/B

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
  int n, t;
	string line;
	cin >> n >> t;
	cin >> line;

	while(t--){
		FR(i,n){
			if(line[i]=='B' && line[i+1]=='G'){
				line[i]='G'; line[i+1]='B'; i++;
			}
		}
	}

	cout << line << endl;

  return 0;
}








