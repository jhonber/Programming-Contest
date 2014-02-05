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

const int N = 505;
char mat[N][N];
map< pair<int,int>,int > visited;

bool check(int n, int m, int i, int j){
  if(i<0 || j<0 || i>n || j>m) return false;
  return true;
}

void solve(pair<int,int> i, int n, int m, int k){
  stack< pair<int,int> > Q;
  Q.push(i);
  visited[i] = true;

  while( !Q.empty() && k ){
    pair<int,int> v = Q.top(); Q.pop();
    visited[v] = true;

    for(int x=1; x<8; x+=2){
      pair<int,int> act = make_pair(v.first + dx[x],v.second + dy[x]);
      if( check(n,m,act.first, act.second) && !visited[act] && mat[act.first][act.second]=='X'){
        Q.push(act);
        visited[act] = true;
      }
    }
    if(k){
     mat[v.first][v.second] = '.';
     k--;
    }
  }
}

int main(){ __
  int n,m,k;
  cin >> n >> m >> k;

  int f = true;
  pair<int,int> init;
  int tot = 0;
  FR(i,n){
    FR(j,m){
      cin >> mat[i][j];
      if(mat[i][j]=='.'){
        tot ++;
        mat[i][j] = 'X';
        if(f){
          init.first = i;
          init.second = j;
          f = false;
        }
      }
    }
  }

  solve(init,n,m,tot-k);

  FR(i,n){
    FR(j,m){
      cout << mat[i][j];
    }
    cout << endl;
  }

  return 0;
}
