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
#define MAXNODES 1000

typedef long long int i6;
typedef vector<i6> vl;
typedef vector<int> vi;
typedef vector<int,int> vii;
typedef vector<vi> vvi;
typedef pair <int,int> pii;

int main(){
	int n;
	cin >> n;

  vi v(101,0);

  FR(i,n){
    int t; cin >> t;
    v[t] = true;
  }

  vi ans;
  int f = false;
  int f2 = false;

  if(v[0]) ans.PB(0);
  if(v[100]) ans.PB(100);

  for(int i=10; i<100; i+=10){
    if(v[i]){
      ans.PB(i);
      f = true;
      break;
    }
  }
  
  if(!f){
    for(int i=11; i<=99; i++){
      if(i%10==0) continue;
      if(v[i]){
        ans.PB(i);
        f2 = true;
        break;
      }
    }
  }

  if(!f2){
    fr(i,1,10){
      if(v[i]){
        ans.PB(i);
        break;
      }
    }
  }
  
  cout << ans.size() << endl;
  FR(i,ans.size()) cout << ans[i] << " ";
  
	return 0;
}



