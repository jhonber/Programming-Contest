#include<bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

#define fr(i,j,n) for(int i=j;i<n;i++)
#define FR(i,n) fr(i,0,n)
#define foreach(it, x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define all(x) x.begin(),x.end()
#define D(x) cout << #x " = " << (x) << endl;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

int dx[8] = {-1,-1,-1,0,1,1, 1, 0};
int dy[8] = {-1, 0, 1,1,1,0,-1,-1};

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

const int N = 105;
int n,m;
int ans = -1;
map< int,set<int> > mapa;
set<int> paila;
vi visited(N);

bool join(set<int> i, set<int> j){
  set<int> :: iterator it = i.begin();
  for( ;it!=i.end(); ++it){
    if( j.count(*it) ) return true;
  }
  return false;
}

void solve( int i){
  if( paila.count(i) ) return;
  ans ++;
  stack< int > Q;
  Q.push(i);

  while( !Q.empty() ){
    int v = Q.top(); Q.pop();
    visited[v] = true;

    fr(x,1,n+1){
      if(x==v) continue;

      if( !paila.count(x) && join(mapa[v], mapa[x]) && !visited[x]){
        visited[x] = true;
        Q.push(x);
      }
    }
  }
}

int main(){
  cin >> n >> m;

  int t,t2;
  FR(i,n){
    cin >> t;
    if(!t) paila.insert(i+1);

    FR(j,t){
      cin >> t2;
      mapa[i+1].insert(t2);
    }
  }

  FR(i,n){
    if(!visited[i+1])
      solve(i+1);
  }

  ans = ans < 0 ? 0 : ans;
  cout << ans + paila.size() << endl;

  return 0;
}