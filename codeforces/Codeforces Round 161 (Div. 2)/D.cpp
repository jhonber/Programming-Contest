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
typedef vector<vi> vvi;
typedef pair<int,int> pii;

struct node {
  int id, cost;
  char color;
};

const int MAXN = 100005;
int k,n;
vvi G(MAXN);
map<int,char> colors;
map<int,int> costs;
vi visited(MAXN);

bool solve(int i){
  stack < node > Q;
  node t;
  t.id = i; t.cost = 0; t.color='W';
  Q.push( t );

  FR(x,n) colors[x+1] = 'W';

  while( !Q.empty() ){
    int v = Q.top().id;
    int cost = Q.top().cost;
    char color = Q.top().color;
    int leaf = true;
    visited[v] = true;

    if(color=='W') {
      Q.top().color = colors[v] = 'G';
      Q.top().cost = costs[v] = cost;
    }
    else goto here;

    FR(x,G[v].size()){
      if( colors[G[v][x]] == 'W' ){
        leaf = false;
        node t;
        t.id = G[v][x]; t.cost = cost+1; t.color = 'W';
        Q.push( t );
      }
      else if( colors[G[v][x]]=='G' ){
        int t = cost - costs[G[v][x]];
        if(t+1>=k+1){
          cout << t+1 << endl;
          while( !Q.empty() ){
            int t = Q.top().id;
            char color = Q.top().color; Q.pop();
            if(color=='G') {
              cout << t << " ";
              if(t==G[v][x]) break;
            }
          }

          return true;
        }
      }
    }

    here :
    if(leaf){
      colors[v] = 'W';
      Q.pop();
    }

  }

  return false;
}

int main(){
  int m,a,b;
  cin >> n >> m >> k;

  FR(i,m){
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  FR(i,n){
    if(!visited[i+1])
      if(solve(i+1))
        break;
  }

  return 0;
}
