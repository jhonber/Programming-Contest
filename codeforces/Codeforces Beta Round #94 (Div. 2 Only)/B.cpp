// http://codeforces.com/contest/129/problem/B

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

const int MAXN = 105;

int main(){
  set<int> G[MAXN];
  int n,m,a,b;
  cin >> n >> m;

  FR(i,m){
    cin >> a >> b;
    G[a].insert(b);
    G[b].insert(a);
  }

  int ans = 0;
  vi paila(MAXN);

  while(true){
    int f = true;
    vector<pii> deleted;
    fr(i,1,n+1){
      if(G[i].size()==1){
        int t = *G[i].begin();
        G[i].erase(t);
        deleted.push_back(make_pair(t,i));
        f = false;
      }
    }
    FR(i,deleted.size()) G[deleted[i].first].erase(deleted[i].second);
    if(f) break;
    ans ++;
  }

  cout << ans << endl;
}