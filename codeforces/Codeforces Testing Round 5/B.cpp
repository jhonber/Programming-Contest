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

struct Node {
  int id, sig;
};

const int N = 105;
int n;
vector< pii > chips(N);
//vi visited(N);

int comp(pii i, int sig, pii j){
  if( sig ){
    if( i.second == j.first ) return 1;
    if( i.second == j.second ) return 0;
  }
  else {
    if( i.first == j.first ) return 1;
    if( i.first == j.second ) return 0;
  }
  return -1;
}

bool solve(int i, int sig){
  stack<Node> Q;
  Node t;
  t.id = i; t.sig = sig;
  Q.push(t);
  int level = 0;
  vector< pii > ans;
  int cont = 0;
  vi visited(N);

  while( !Q.empty() && cont < 200 ){
    cont++;
//    int temp; cin >> temp;
    int v = Q.top().id;
    int s = Q.top().sig;
    int leaf = true;

    if(visited[v]){
      visited[v] = false;
      level --;
      ans.pop_back();
      Q.pop();
      continue;
    }

    ans.push_back(make_pair(v,s));
    visited[v] = true;
    level ++;

    FR(x,n){
      if(!visited[ x+1 ]){
        int tmp = comp( chips[v],s,chips[x+1] );
        if( tmp != -1 ){
//          D(x+1);
          leaf = false;
          t.id = x+1; t.sig = tmp;
          Q.push( t );
        }
      }
    }

//    D(leaf);
    if(leaf){
//      D(level);
      if(level==n){
        FR(xx,n){
//          cout << "*" <<ans[xx].first << " " << chips[ans[xx].first].first << " " << chips[ans[xx].first].second << " " << (ans[xx].second == 0 ? "-" : "+") << endl;
          cout << ans[xx].first << " " << (ans[xx].second == 0 ? "-" : "+") << endl;
        }
        return true;
      }
      visited[v] = false;
      level --;
      ans.pop_back();
      Q.pop();
    }


  }

  return false;
}

int main(){
  int a,b;
  cin >> n;

  FR(i,n){
    cin >> a >> b;
    chips[i+1] = make_pair(a,b);
  }

  FR(i,n){
    if(solve(i+1,1) || solve(i+1,0)) return 0;
  }

  cout << "No solution" << endl;

  return 0;
}
