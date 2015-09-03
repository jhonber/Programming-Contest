// http://codeforces.com/contest/378/problem/C

using namespace std;
#include<bits/stdc++.h>
#define __ ios_base::sync_with_stdio(0);cin.tie(0);

#define PI acos(-1)
#define fr(i,j,n) for(int i=j;i<n;++i)
#define FR(i,n) fr(i,0,n)
#define foreach(it, x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
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
const int N = 250000;

vvi G(N+10);
vi visited(N+10);
vi visited2(N+10);
vi children(N+10);
vi mefather(N+10);
vi deleted(N+10);
vi vleafs;
int leafs = 0;

char mat [500+10][500+10];
map<int,pii> mapa;
map<pii,int> mapa2;

void dfs(int i){
	stack<int> Q;
	Q.push(i);

	while(!Q.empty()){
		int v = Q.top(); Q.pop();
    pii vv = mapa[v];
    visited[ mapa2[vv] ] = true;
    int leaf = true;

    for(int i=1; i<8; i+=2){
      pii xy = MK(vv.F + dx[i],vv.S + dy[i]);
      if( mat[xy.F][xy.S] == '.' && !visited[ mapa2[xy] ] ){
        G[v].PB(mapa2[xy]);
        Q.push(mapa2[xy]);
        visited[mapa2[xy]] = true;
        children[mapa2[vv]] ++;
        mefather[ mapa2[xy] ] = mapa2[vv];
        leaf = false;
      }
    }
    if(leaf){
      leafs++;
      vleafs.PB( mapa2[vv] );
    }
  }
}

void solve(int i, int k){
  int x = 0, k2 = k;
  while( x < vleafs.size() && k2 ){
    deleted[ vleafs[x] ] = true;
    children[ mefather[vleafs[x]] ] --;
    x++;
    k2--;
  }

  if(k > leafs){
    k -= x;
    stack<int> Q;
    Q.push(i);

    while(!Q.empty() && k){
      int v = Q.top();

      FR(xx,G[v].size()){
        if( !deleted[ G[v][xx] ] && !visited2[G[v][xx]] ){
          visited2[ G[v][xx] ] = true;
          Q.push( G[v][xx] );
        }
      }
      if( !children[v] ){
        deleted[ v ] = true;
        children[ mefather[ v ] ] --;
        k--;
        Q.pop();
      }
    }
  }
}

int main(){ __
  int n,m,k;
  cin >> n >> m >> k;

  int init;
  int f = true, c = 1;
  fr(i,1,n+1){
    fr(j,1,m+1){
      cin >> mat[i][j];
      if(mat[i][j]=='.' ){
        if(f){
          init = c;
          f = false;
        }
        mapa[c] = MK(i,j);
        mapa2[ mapa[c] ] = c;
      }
      c++;
    }
  }

  dfs(init);

  solve(init,k);

  fr(i,1,n+1){
    fr(j,1,m+1){
      if( deleted[mapa2[MK(i,j)]] ) cout << "X";
      else cout << mat[i][j];
    }
    cout << endl;
  }

  return 0;
}
