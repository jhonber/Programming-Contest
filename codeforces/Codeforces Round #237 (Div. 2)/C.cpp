// http://codeforces.com/contest/404/problem/C

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

int main(){
  int n,k;
  cin >> n >> k;

  vector< pair<int,int> > v;
  for(int i=0; i<n; ++i){
    int t;
    cin >> t;
    v.push_back( make_pair(t,i) );
  }

  sort(all(v));

  vector<int> G[n];
  int i = 0, j = 0;
  int size = 0;

  while( i<n && j<n ){
    int inside = false;
    while(j+1<n && v[i].first == v[j+1].first-1 && G[v[i].second].size() < k && G[v[j+1].second].size() < k){
      G[v[i].second].push_back( v[j+1].second );
      G[v[j+1].second].push_back( v[i].second );

      size ++;
      j++;
      inside = true;
    }
    if(!inside && v[i].first == v[j].first)
      j++;

    i++;
  }

  vector<int> visited(n,0);
  stack<int> Q;
  Q.push( v[0].second );
  int cont = 1;
  visited[ v[0].second ] = true;

  while(!Q.empty()){
    int act = Q.top(); Q.pop();

    for(int i = 0; i<G[act].size(); ++i){
      if(!visited[ G[act][i] ]){
        visited[ G[act][i] ] = true;
        cont ++;
        Q.push( G[act][i] );
      }
    }
  }

  if(cont == n && !v[0].first){
    set< pair<int,int> > ready;
    cout << size << endl;
    for(int i=0; i<n; ++i){
      for(int j=0; j<G[i].size(); ++j){
        pair<int,int> e;
        e.first = min(i+1,G[i][j]+1);
        e.second = max(G[i][j]+1,i+1);
        if(ready.count(e) == 0){
          ready.insert(e);
          cout << i+1 << " " << G[i][j]+1 << endl;
        }
      }
    }
  }
  else cout << -1 << endl;

  return 0;
}