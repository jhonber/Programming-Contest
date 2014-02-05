using namespace std;
#include<bits/stdc++.h>
#define __ ios_base::sync_with_stdio(0);cin.tie(0);

#define PI acos(-1)
#define fr(i,j,n) for(int i=j;i<n;++i)
#define FR(i,n) fr(i,0,n)
#define foreach(it, x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
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

int dx[8] = {-1,-1,-1,0,1,1, 1, 0};
int dy[8] = {-1, 0, 1,1,1,0,-1,-1};

typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef pair <int,int> pii;
typedef vector<pii> vpii;
const int N = 100000;

vvi G(N+10);
vi visited(N+10);
map <int,int> bad;
vi repaila(N+10);
vi ans;

bool dfs(int i){
	stack<int> Q;
	Q.push(i);
  set<int> forbidden;
  set<int> good;
  bad[i] = 0;

	while(!Q.empty()){
		int v = Q.top(); Q.pop();
    visited[v] = true;
    
		FR(w,G[v].size()){
      int child = G[v][w];

			if( !visited[child] ){
        if( repaila[child] ){
          if( bad[v] )
            forbidden.insert(bad[v]);
          bad[child] = child;
        }
        else bad[child] = bad[v];

        Q.push(child);
			}
		}
    
    if( G[v].size()==1 && bad[v] ) good.insert( bad[v] ); 
  }
  
  foreach(i,good)
    if( forbidden.count(*i)==0 ) ans.PB(*i);
  
}

int main(){
  int n,a,b,c;
  cin >> n;
  
  FR(i,n-1){
    cin >> a >> b >> c;
    G[a].PB(b);
    G[b].PB(a);
    if(c==2) repaila[b] = repaila[a] = true;
  }

  dfs(1);

  cout << ans.size() << endl;
  FR(i,ans.size()) cout << ans[i] << " ";
  return 0;
}
