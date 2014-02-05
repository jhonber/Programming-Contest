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
  int n, m, tmp;
  cin >> n >> m;
  map<int,int> mapa;
  vi vv(m*3);

  FR(i,m*3) cin >> vv[i];

  for(int i=0;i<(m*3); i += 3){
    vi v(3,0);
    FR(j,3){
      FR(x,3){
        if( mapa[vv[i+x]] )
          v[ mapa[vv[i+x]]-1 ] = true;
      }
      
      if( !mapa[vv[i+j]] ){
        int t = 0;
        FR(x,3){
          if(!v[x]){
            t = x+1;
            break;
          }
        }
        mapa[ vv[i+j] ] = t;
      }
    }
  }

  map<int,int> :: iterator it = mapa.begin();
  for(;it!=mapa.end();++it)
    cout << it->S << " ";
}
