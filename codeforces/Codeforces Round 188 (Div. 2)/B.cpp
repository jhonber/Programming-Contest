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
#define MAXNODES 1000

typedef long long int ll;
typedef vector<ll> vl;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<int,int> vii;
typedef vector<vi> vvi;
typedef pair <int,int> pii;
typedef pair <ll,ll> pll;
#define MAXN 100000

int main(){
  string s;
  cin >> s;

  ll h=0, ans=0;
  FR(i,s.size()){
    int f = false, f2 = false;
    if(s.substr(i,5) == "heavy"){
      h++;
    }
    else if(s.substr(i,5) == "metal"){
      ans += h;
    }
  }

  cout << ans;
  return 0;
}




















