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
  int c1,c2,c3,c4,n,m;
  cin >> c1 >> c2 >> c3 >> c4 >> n >> m;
  vi v1(n),v2(m);

  FR(i,n) cin >> v1[i];
  FR(i,m) cin >> v2[i];

  int ans = INT_MAX;
  int tmp = 0;
  FR(i,n) tmp += v1[i]*c1;
  FR(i,m) tmp += v2[i]*c1;

  ans = min(ans,tmp);

  tmp = (c2*n) + (c2*m);

  ans = min(ans,tmp);
  
  tmp = (c3*2);
  
  ans = min(ans,tmp);
  
  tmp = c4;

  ans = min(ans,tmp);
  
  int t = 0;
  FR(i,n) t += min( v1[i]*c1,c2 );
  t = min(t,c3);

  int t2 = 0;
  FR(i,m) t2 += min( v2[i]*c1,c2 );
  t2 = min(t2,c3);

  ans = min(ans,t+t2);
  
  cout << ans;

  return 0;
}
