// http://codeforces.com/contest/353/problem/A

using namespace std;
#include<bits/stdc++.h>
#define __ ios_base::sync_with_stdio(0);cin.tie(0);

#define PI acos(-1)
#define fr(i,j,n) for(int i=j;i<n;++i)
#define FR(i,n) fr(i,0,n)
#define all(x) x.begin(),x.end()
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

int main(){ 
  int n;
  cin >> n;
  vpii v;
  FR(i,n){
    int a,b;
    cin >> a >> b;
    v.PB(MK(a,b));
  }

  int parimpar = 0, imparimpar = 0, parespares = 0, impa = 0, impb = 0;
  FR(i,n){
    if(v[i].F%2 !=0 && v[i].S%2 ==0 || v[i].S%2 !=0 && v[i].F%2 ==0) parimpar ++;
    if(v[i].F%2 ==0 && v[i].S%2 ==0 ) parespares ++;
    if(v[i].S%2 !=0 && v[i].F%2 !=0) imparimpar ++;
    if(v[i].F%2!=0) impa++;
    if(v[i].S%2!=0) impb++;
  }
  if(imparimpar==0 && parimpar%2==0 || parimpar==0 && imparimpar%2==0){
    if(impa%2==0 && impb%2==0) cout << 0;
    else cout << 1;
  }
  else if(parimpar && parimpar%2==0 && imparimpar>0){
    if(impa%2==0 && impb%2==0) cout << 0;
    else cout << 1;
  }
  else cout << -1;
  
  return 0;
}
