// http://codeforces.com/contest/96/problem/B

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

set<ll> lucky;

ll vec_to_ll(vi v){
  ll p = 1;
  ll ans = 0;
  for(ll i=v.size()-1; i>=0; i--){
    ans += v[i]*p;
    p *= 10;
  }
  return ans;
}

void gen(){
  fr(k,1,6){
    vi t;
    FR(i,k) t.PB(4);
    FR(i,k) t.PB(7);

//    cout << vec_to_ll(t) << endl;
    do{
      lucky.insert(vec_to_ll(t));
//      D(vec_to_ll(t));
    } while(next_permutation(t.begin(),t.end()));
  }
}


int main(){
  gen();
  ll n;
  cin >> n;
  if(binary_search(lucky.begin(),lucky.end(),n)) cout << n << endl;
  else {
    set<ll> :: iterator up;
    up = lucky.upper_bound(n);
    cout << *up << endl;
  }
  return 0;
}