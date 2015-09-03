// http://codeforces.com/contest/34/problem/C

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

#define MPI acos(-1)
#define fr(i,j,n) for(int i=j;i<n;++i)
#define FR(i,n) fr(i,0,n)
#define foreach(x,v) for(typeof (v).begin() x = (v).begin(); x!= (v).end(); x++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define RI(x) scanf("%d",&x)
#define DRI(x) int x;RI(x)
#define RII(x,y) scanf("%d%d",&x,&y)
#define DRII(x,y) int x,y;RII(x,y)
#define PI(x) printf("%d ",x)
#define PIS(x) printf("%d\n",x)
#define D(x) cout<< #x " = "<<(x)<<endl
#define Dd(x) printf("#x = %lf\n", x)
#define Dbg if(1)
#define PB push_back
#define MK make_pair
#define F first
#define S second

typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<int,int> vii;
typedef vector<vi> vvi;
typedef pair <int,int> pii;
typedef pair <double,double> pdd;

int main(){
  string line;
  getline(cin,line);
  istringstream spt(line);

  vi v;
  for(string s; getline(spt,s,',');) v.PB(toInt(s));
  v.PB(100000);
  sort(all(v));

  string ans = "";
  vi v2;
  int t=0;
  FR(i,v.size()-1){
    if(v[i]+1==v[i+1]) continue;
    else if(v[i]!=v[i+1]){
      v2.PB(v[t]); v2.PB(0); v2.PB(v[i]);
      t=i+1;
    }
  }
//  FR(i,v2.size()) cout << v2[i] << " ";
//  cout << endl;
  FR(i,v2.size()-1) if(v2[i]==0 && v2[i-1]==v2[i+1]) v2.erase(v2.begin()+i, v2.begin()+i+2);
//  FR(i,v2.size()) cout << v2[i] << " ";
//  cout << endl;
  v2.PB(100000);
  FR(i,v2.size()){
    if(v2[i]==100000) break;
    if(v2[i+1]==0){
      ans += toStr(v2[i]) + "-" + toStr(v2[i+2]) + ",";
      i+=2;
    }
    else ans += toStr(v2[i]) + ",";
  }
  ans.erase(ans.size()-1);
  cout << ans <<endl;

  return 0;
}









