// http://codeforces.com/contest/362/problem/A

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

int dx[4] = {-2,2, 2,-2};
int dy[4] = { 2,2,-2,-2};

typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef pair <int,int> pii;
typedef vector<pii> vpii;

char mat[10][10];
vpii pos;
map< pii,int > visited;
map< pii,int > dist;

bool check(pii xy){
  if( xy.F < 0 || xy.S < 0 || xy.F >= 8 || xy.S >= 8 ) return false;
  return true;
}

bool solve(){
  queue< pii > Q;
  Q.push(pos[0]);
  visited[pos[0]] = true;

  while( !Q.empty() ){
    pii act = Q.front(); Q.pop();
    FR(i,4){
      int x = act.F + dx[i];
      int y = act.S + dy[i];
      pii xy = MK(x,y);
      
      if( !visited[xy] && check( xy ) ){
        visited[xy] = true;
        dist[xy] += dist[act] + 1;
        if(x == pos[1].F && y == pos[1].S){
          if(dist[xy]%2 == 0) return true;
          else return false;
        }
        Q.push(xy);
      }
    }
  }
  return false;
}

int main(){
  int n;
  cin >> n;
  
  FR(i,n){
    pos.clear();
    visited.clear();
    dist.clear();

    FR(j,8){
      FR(k,8){
        cin >> mat[j][k];
        if(mat[j][k]=='K') pos.PB(MK(j,k));
      }
    }

    if(solve()) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}
