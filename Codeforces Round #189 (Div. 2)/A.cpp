// http://codeforces.com/contest/320/problem/A

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

bool check(string s){
	FR(i,s.size()) if(s[i]!='1' && s[i]!='4') return false;
	return true;
}

int main(){
	string s;
	cin >> s;

	if(!check(s)){
		cout << "NO";
		return 0;
	}
	
	int ans = true, i = 0;
	while( i < s.size() ){
		if(s[i]=='1' && s[i+1]=='4' && s[i+2]=='4') i += 3;
		else if(s[i]=='1' && s[i+1]=='4') i += 2;
		else if(s[i]=='1') i++;
		else {
			ans=false;
			break;
		}
	}

	ans ? cout << "YES" : cout << "NO";	

	return 0; 
}


