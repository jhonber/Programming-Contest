// http://codeforces.com/contest/284/problem/A

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
#define fr(i,j,n) for(int i=j;i<n;i++)
#define FR(i,n) fr(i,0,n)
#define foreach(x,v) for(typeof (v).begin() x = (v).begin(); x!= (v).end(); x++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define D(x) cout<< #x " = "<<(x)<<endl
#define Dbg if(1)
#define PB push_back
#define MAXNODES 1000

typedef long long int li;
typedef vector<li> vli;
typedef vector<int> vi;
typedef vector<int,int> vii;
typedef vector<vi> vvi;
typedef pair <int,int> pii;

int gcd(int a, int b){
  while( b!=0 ){
    int t = b;
    b = a%t;
    a = t;
  }
  return a;
}

int main(){
  int p,res=0;
  cin >> p;
  if(p==2){
    cout << 1 << endl;
    return 0;
  }
  p--;
  fr(x,1,p) if( gcd(p,x)==1 ) res++;
  cout << res << endl;
  return 0;
}




