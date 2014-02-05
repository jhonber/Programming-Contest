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
template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

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

bool comp(int a, int b){
	return a > b;
}

vi int_to_vec(string n){
	vi v;
	FR(i,n.size()) v.PB(toInt(n[i]));
	return v;
}

int main(){
	string a,s;
	cin >> a >> s;
	vi v1 = int_to_vec(a);
	vi v2 = int_to_vec(s);

	sort(all(v2),comp);

	int t = 0;
	FR(i,v2.size()){
		fr(j,t,v1.size()){
			if(v1[j]<v2[i]) { cout << v2[i]; t=j+1; break;}
			else cout << v1[j];
			if(j==v1.size()-1) return 0;
		}
	}
	fr(i,t,v1.size()) cout << v1[i];

	return 0;
}