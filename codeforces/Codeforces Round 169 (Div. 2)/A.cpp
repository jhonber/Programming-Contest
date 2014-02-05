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
#define MAX -1000000000

typedef long long int i6;
typedef vector<int> vi;
typedef vector<int,int> vii;
typedef vector<vi> vvi;
typedef pair <int,int> pii;

const double pi=acos(-1);

int main(){
  int n,k,t,f;
  int max1=MAX,max2=MAX;

  cin >> n >> k;
  while(n--){
    cin >> f >> t;
    
    if( (f - (t-k)) > max1 && t>k) max1 = (f - (t-k));
    if(f > max2 && t <= k) max2 = f;
  }

  cout << (max1 > max2 ? max1 : max2) << endl;

  return 0;
}



