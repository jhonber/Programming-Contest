// http://codeforces.com/contest/370/problem/A

#include<bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

#define foreach(it, x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define all(x) x.begin(),x.end()
#define D(x) cout << #x " = " << (x) << endl;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

int dx[8] = {-1,-1,-1,0,1,1, 1, 0};
int dy[8] = {-1, 0, 1,1,1,0,-1,-1};

int chess[8][8];

int rook(int i, int j, int i2, int j2){
  if(i == i2 && j == j2)
    return 0;
  if(i==i2 || j==j2)
    return 1;
  return 2;
}

int bishop(int i, int j, int i2, int j2){
  if(i == i2 && j == j2)
    return 0;

  if(chess[i][j] != chess[i2][j2])
    return 0;

  for(int x = i, y = j; x<8 && x>=0; --x, ++y){
    if(i2==x && j2==y)
      return 1;
  }

  for(int x = i, y = j; x<8 && x>=0; ++x, --y){
    if(i2==x && j2==y)
      return 1;
  }

  for(int x = i, y = j; x<8 && x>=0; ++x, ++y){
    if(i2==x && j2==y)
      return 1;
  }

  for(int x = i, y = j; x<8 && x>=0; --x, --y){
    if(i2==x && j2==y)
      return 1;
  }

  return 2;
}

bool check(int i, int j){
  if(i>=0 && i<8 && j>=0 && j<8 ) return true;
  return false;
}

map< pair<int,int>, int > visited;
map< pair<int,int>, int > path;

int king(int i, int j, int i2, int j2){
  pair<int,int> x = make_pair(i,j);
  pair<int,int> y = make_pair(i2,j2);

  visited[x] = true;
  queue< pair<int,int> > Q;
  Q.push(x);
  path[x] = 0;

  int ans = 0;
  while(!Q.empty()){
    pair<int,int> act = Q.front(); Q.pop();

    for(int i=0; i<8; ++i){
      if(check( act.first + dx[i], act.second + dy[i] )){
        if(!visited[ make_pair(act.first+dx[i], act.second+dy[i]) ]){
          path[make_pair(act.first+dx[i],act.second+dy[i])] = path[act] + 1;
          if( y.first == act.first+dx[i] &&  y.second == act.second+dy[i] )
            return path[act] + 1;
          visited[ make_pair(act.first+dx[i], act.second+dy[i]) ] = true;
          Q.push( make_pair(act.first+dx[i], act.second+dy[i]) );
        }
      }
    }
  }

}

int main(){
  int f;
  int i,j;
  for( i=0; i<8; ++i){
    if(i%2 == 0 && j%2 == 0)
      f = true;
    else
      f = false;

    for(j=0; j<8; ++j){
      chess[i][j] = f;
      f = !f;
    }
  }

  int r1,c1,r2,c2;
  cin >> r1 >> c1 >> r2 >> c2;
  r1 --; c1--; r2--; c2--;

  cout << rook(r1,c1,r2,c2) << " " << bishop(r1,c1,r2,c2) << " " << king( r1,c1,r2,c2 );

  return 0;
}