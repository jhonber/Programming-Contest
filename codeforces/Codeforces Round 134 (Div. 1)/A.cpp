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
int ans = -1;
map<int,pii> all;
vi visited(N);

void solve(int i){
  ans ++;
  stack< int > Q;
  Q.push(i);
  int child = false;

  while( !Q.empty() ){
    int v = Q.top(); Q.pop();
    visited[v] = true;

    fr(x,1,all.size()+1){
      if( !visited[x] && (all[v].first == all[x].first || all[v].second == all[x].second) ){
        child = true;
        visited[x] = true;
        Q.push(x);
      }
    }
  }
}

int main(){
  int n;
  cin >> n;

  int x,y;
  fr(i,1,n+1){
    cin >> x >> y;
    all[i] = make_pair(x,y);
  }

  fr(i,1,n+1)
    if(!visited[i])
      solve(i);

  cout << ans << endl;

  return 0;
}