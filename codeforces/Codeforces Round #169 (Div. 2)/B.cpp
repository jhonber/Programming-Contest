// http://codeforces.com/contest/276/problem/B

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
#define MAX 50

typedef long long int i6;
typedef vector<int> vi;
typedef vector<int,int> vii;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef map<int,i6> mii6;
typedef map<char,int> mci;
typedef vector<char> vc;

int main(){
	string s;
  cin >> s;
  vi letter(30,0);

  FR(i,s.size()) letter[ s[i]-'a' ]++;

  FR(i,30) letter[i] %= 2;

  int res=0;
  FR(i,30) res += letter[i];

  if( res==0 || res%2 ) cout << "First" << endl;
  else cout << "Second" << endl;

  return 0;

}















