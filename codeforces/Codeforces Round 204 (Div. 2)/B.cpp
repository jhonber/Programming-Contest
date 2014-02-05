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

const int M = 100000 + 10;

int main(){__
  int n;  
  cin >> n;

  vi v(n);
  vi ready(n+1,0);
  map<int,int> mapa;

  vvi mat(M);
 
  FR(i,n){
    cin >> v[i];
    mat[v[i]].PB(i+1);
  }
/*
  FR(i,n){
    cout << i << " => ";
    FR(j,mat[i].size()){
      cout << mat[i][j] << " ";
    }
    cout << endl;
  }
*/
  vpii ans;
  FR(i,M){
    if(!mat[i].size()) continue;

    if(mat[i].size()==1){
      ans.PB(MK(i,0));
      continue;
    }

    if(mat[i].size()==2){
      ans.PB(MK(i,mat[i][1]-mat[i][0]));
      continue;
    }

    int f = true, dif = mat[i][1] - mat[i][0];
    FR(j,mat[i].size()-2){
      if( mat[i][j+1]-mat[i][j] !=  mat[i][j+2]-mat[i][j+1] ){
        f=false;
        break;
      }
    }

    if(f) ans.PB(MK(i,dif));
  }
  
  cout << ans.size() << endl;
  FR(i,ans.size()) cout << ans[i].F << " " << ans[i].S << endl;

  return 0;
}
