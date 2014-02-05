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
#define MAX 500

typedef long long int i6;
typedef vector<i6> vl;
typedef vector<int> vi;
typedef vector<int,int> vii;
typedef vector<vi> vvi;
typedef pair <int,int> pii;
typedef pair <i6,i6> pii2;
typedef vector< pii2 > vpii2;
typedef vector< pii > vpii;

int main(){
  int n, res=0,res2=0;
  cin >> n;
  string line;
  cin >> line;

  FR(i,line.size()){
    if(line[i]!='F') res++;
    if(line[i]=='I') res2++;
  }
  if(res2==0) cout << res << endl;
  else if(res2==1) cout << 1 << endl;
  else if(res > 1) cout << 0 << endl;

  return 0;
}



