using namespace std;
#include<bits/stdc++.h>
#define __ ios_base::sync_with_stdio(0);cin.tie(0);

#define PI acos(-1)
#define fr(i,j,n) for(int i=j;i<n;++i)
#define FR(i,n) fr(i,0,n)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define D(x) cout<< #x " = "<<(x)<<endl
#define PB push_back
#define MK make_pair
#define F first
#define S second

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

int dx[8] = {-1,-1,-1,0,1,1, 1, 0};
int dy[8] = {-1, 0, 1,1,1,0,-1,-1};

typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef pair <int,int> pii;
typedef vector<pii> vpii;

bool comp(pii a, pii b){
  return a.S < b.S;
}

int main(){
  int n,tmp;
  cin >> n;

  vector<pii> v;
  FR(i,n){
    int t;
    cin >> t;
    v.PB(MK(t,i));
  }

  sort(all(v));
  vector<pii> v2 = v;
  int last;

  FR(i,n-1){
    if(v[i].F == v[i+1].F){
      last = v2[i].F+1;
      v2[i+1].F = last;
    }
    else if(last>=v[i+1].F){
      v2[i+1].F = last+1;
      last++;
    }
  }

  sort(v2.begin(),v2.end(),comp);

  FR(i,n) cout << v2[i].F << " ";

  return 0;
}
