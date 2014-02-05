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

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

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
#define MK make_pair
#define MAXNODES 1000

typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<int,int> vii;
typedef vector<string> vs;

bool comp(const int a, const int b){ return a<b;}

int main(){
 	string s;
	vs mat;
	while(cin >> s) mat.PB(s);
	int n = mat.size();
	int m = mat[0].size();

	if(n < 2 || m < 2){
		cout << "NO";
		return 0;
	}

	FR(i,n){
		FR(j,m){
			int c1 = 0, c2=0;
			if(mat[i][j]=='#') c1++;
			if(j+1<m && mat[i][j+1]=='#') c1++;
			if(i+1<n && mat[i+1][j]=='#') c1++;
			if(i+1<n && j+1 <m && mat[i+1][j+1]=='#') c1++;

			if(mat[i][j]=='.') c2++;
			if(j+1<m && mat[i][j+1]=='.') c2++;
			if(i+1<n && mat[i+1][j]=='.') c2++;
			if(i+1<n && j+1 <m && mat[i+1][j+1]=='.') c2++;

			if(c1>=3 || c2>=3){
				cout << "YES";
				return 0;
			}
		}
	}

	cout << "NO";
  return 0;
}

