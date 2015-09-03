// http://codeforces.com/contest/441/problem/C

#include<bits/stdc++.h>
using namespace std;

#define __ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define foreach(it, x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define all(x) x.begin(),x.end()
#define D(x) cout << #x " = " << (x) << endl;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

int dx[8] = {-1,-1,-1,0,1,1, 1, 0};
int dy[8] = {-1, 0, 1,1,1,0,-1,-1};

int n,m;
int mat[310][310];

void print (vector< pair<int,int> > v){
  cout << v.size() << " ";
  for (int i=0; i<v.size(); ++i)
    cout << v[i].first << " " << v[i].second << " ";
  cout << endl;
}

bool good(int i, int j){
  if(i>=1 && i<n+1 && j>=1 && j<m+1 && !mat[i][j]){
    mat[i][j] = true;
    return true;
  }
  return false;
}

pair<int,int> f(pair<int,int> act){
  if( good( act.first, act.second+1 ) )
    return make_pair(act.first,act.second+1);

  if( good( act.first+1, act.second ) )
    return make_pair(act.first+1,act.second);

  if( good( act.first, act.second-1 ) )
    return make_pair(act.first,act.second-1);

  if( good( act.first-1, act.second ) )
    return make_pair(act.first-1,act.second);

  return make_pair(-1,-1);
}

int main(){__
  int kk;
  cin >> n >> m >> kk;

  memset(mat,0,sizeof mat);
  int s = (n*m)/kk;

  int k=1, cont = 1;
  vector< pair<int,int> > tube;
  pair<int,int> act = make_pair(1,1), next;
  mat[1][1] = true;
  tube.push_back(act);

  for ( ; k < (n*m); ++k ){
    next = f(act);
    if ( tube.size() == s ){
      print(tube);
      tube.clear();
      cont ++;
    }
    act = next;
    if(cont >= kk) break;
    tube.push_back(next);
  }

  tube.push_back(act);

  for ( ;k <= (n*m); ++k ){
    next = f(act);
    if ( next.first == -1 ) break;
    tube.push_back(next);
    act = next;
  }

  print(tube);

  return 0;
}
